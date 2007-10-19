#include "mitkToolManager.h"
#include "mitkGlobalInteraction.h"

#include <itkObjectFactoryBase.h>
#include <itkCommand.h>

#include <list>

mitk::ToolManager::ToolManager(const char* groups)
:m_ActiveTool(NULL),
 m_ActiveToolID(-1),
 m_RegisteredClients(0)
{
  // get a list of all known mitk::Tools
  std::list<itk::LightObject::Pointer> thingsThatClaimToBeATool = itk::ObjectFactoryBase::CreateAllInstance("mitkTool");

  std::string allowedGroups;
  if (groups != NULL)
  {
    allowedGroups = groups;
  }

  // remember these tools
  for ( std::list<itk::LightObject::Pointer>::iterator iter = thingsThatClaimToBeATool.begin();
        iter != thingsThatClaimToBeATool.end();
        ++iter )
  {
    if ( Tool* tool = dynamic_cast<Tool*>( iter->GetPointer() ) )
    {
      tool->SetToolManager(this); // important to call right after instantiation
      if ( (groups == NULL) || ( allowedGroups.find( tool->GetGroup() ) != std::string::npos ) ||
                               ( allowedGroups.find( tool->GetName() ) != std::string::npos ) 
                               )
      {
        m_Tools.push_back( tool );
      }
    }
  }

  //ActivateTool(0); // first one is default
}

mitk::ToolManager::~ToolManager()
{
}

const mitk::ToolManager::ToolVectorTypeConst mitk::ToolManager::GetTools()
{
  ToolVectorTypeConst resultList;

  for ( ToolVectorType::iterator iter = m_Tools.begin();
        iter != m_Tools.end();
        ++iter )
  {
    resultList.push_back( iter->GetPointer() );
  }

  return resultList;
}

mitk::Tool* mitk::ToolManager::GetToolById(int id)
{
  try
  {
    return m_Tools.at(id);
  }
  catch(std::exception&)
  {
    return NULL;
  }
}

bool mitk::ToolManager::ActivateTool(int id)
{
  if ( GetToolById( id ) == m_ActiveTool ) return true; // no change needed

  if (m_ActiveTool)
  {
    m_ActiveTool->Deactivated();
    mitk::GlobalInteraction::GetInstance()->RemoveListener( m_ActiveTool );
  }

  m_ActiveTool = GetToolById( id );
  m_ActiveToolID = m_ActiveTool ? id : -1; // current ID if tool is valid, otherwise -1

  if (m_ActiveTool)
  {
    if (m_RegisteredClients)
    {
      m_ActiveTool->Activated();
      mitk::GlobalInteraction::GetInstance()->AddListener( m_ActiveTool );
    }
  }

  InvokeEvent( ToolSelectedEvent() );

  return (m_ActiveTool != NULL);
}

void mitk::ToolManager::SetReferenceData(DataVectorType data)
{
  if (data != m_ReferenceData)
  {
    // remove observers from old nodes
    for ( DataVectorType::iterator dataIter = m_ReferenceData.begin(); dataIter != m_ReferenceData.end(); ++dataIter )
    {
      NodeTagMapType::iterator searchIter = m_ReferenceDataObserverTags.find( *dataIter );
      if ( searchIter != m_ReferenceDataObserverTags.end() )
      {
        //std::cout << "Stopping observation of " << (void*)(*dataIter) << std::endl;
        (*dataIter)->RemoveObserver( searchIter->second );
      }
    }

    m_ReferenceData = data;
    // TODO tell active tool?

    // attach new observers
    m_ReferenceDataObserverTags.clear();
    for ( DataVectorType::iterator dataIter = m_ReferenceData.begin(); dataIter != m_ReferenceData.end(); ++dataIter )
    {
      //std::cout << "Observing " << (void*)(*dataIter) << std::endl;
      itk::MemberCommand<ToolManager>::Pointer command = itk::MemberCommand<ToolManager>::New();
      command->SetCallbackFunction( this, &ToolManager::OnOneOfTheReferenceDataDeleted );
      command->SetCallbackFunction( this, &ToolManager::OnOneOfTheReferenceDataDeletedConst );
      m_ReferenceDataObserverTags.insert( std::pair<DataTreeNode*, unsigned long>( (*dataIter), (*dataIter)->AddObserver( itk::DeleteEvent(), command ) ) );
    }

    InvokeEvent( ToolReferenceDataChangedEvent() );
  }
}

void mitk::ToolManager::OnOneOfTheReferenceDataDeletedConst(const itk::Object* caller, const itk::EventObject& e)
{
  OnOneOfTheReferenceDataDeleted( const_cast<itk::Object*>(caller), e );
}

void mitk::ToolManager::OnOneOfTheReferenceDataDeleted(itk::Object* caller, const itk::EventObject& e)
{
  //std::cout << "Deleted: " << (void*)caller << " Removing from reference data list." << std::endl;
  DataVectorType v;

  for (DataVectorType::iterator dataIter = m_ReferenceData.begin(); dataIter != m_ReferenceData.end(); ++dataIter )
  {
    //std::cout << " In list: " << (void*)(*dataIter);
    if ( (void*)(*dataIter) != (void*)caller )
    {
      v.push_back( *dataIter );
      //std::cout << " kept" << std::endl;
    }
    else
    {
      //std::cout << " removed" << std::endl;
      m_ReferenceDataObserverTags.erase( *dataIter ); // no tag to remove anymore
    }
  }
  this->SetReferenceData( v );
}

void mitk::ToolManager::SetReferenceData(DataTreeNode* data)
{
  //std::cout << "ToolManager::SetReferenceData(" << (void*)data << ")" << std::endl;
  DataVectorType v;
  v.push_back(data);
  SetReferenceData(v);
}

void mitk::ToolManager::SetWorkingData(DataVectorType data)
{
  if ( data != m_WorkingData )
  {
    // remove observers from old nodes
    for ( DataVectorType::iterator dataIter = m_WorkingData.begin(); dataIter != m_WorkingData.end(); ++dataIter )
    {
      NodeTagMapType::iterator searchIter = m_WorkingDataObserverTags.find( *dataIter );
      if ( searchIter != m_WorkingDataObserverTags.end() )
      {
        //std::cout << "Stopping observation of " << (void*)(*dataIter) << std::endl;
        (*dataIter)->RemoveObserver( searchIter->second );
      }
    }

    m_WorkingData = data;
    // TODO tell active tool?

    // attach new observers
    m_WorkingDataObserverTags.clear();
    for ( DataVectorType::iterator dataIter = m_WorkingData.begin(); dataIter != m_WorkingData.end(); ++dataIter )
    {
      //std::cout << "Observing " << (void*)(*dataIter) << std::endl;
      itk::MemberCommand<ToolManager>::Pointer command = itk::MemberCommand<ToolManager>::New();
      command->SetCallbackFunction( this, &ToolManager::OnOneOfTheWorkingDataDeleted );
      command->SetCallbackFunction( this, &ToolManager::OnOneOfTheWorkingDataDeletedConst );
      m_WorkingDataObserverTags.insert( std::pair<DataTreeNode*, unsigned long>( (*dataIter), (*dataIter)->AddObserver( itk::DeleteEvent(), command ) ) );
    }

    InvokeEvent( ToolWorkingDataChangedEvent() );
  }
}

void mitk::ToolManager::OnOneOfTheWorkingDataDeletedConst(const itk::Object* caller, const itk::EventObject& e)
{
  OnOneOfTheWorkingDataDeleted( const_cast<itk::Object*>(caller), e );
}

void mitk::ToolManager::OnOneOfTheWorkingDataDeleted(itk::Object* caller, const itk::EventObject& e)
{
  //std::cout << "Deleted: " << (void*)caller << " Removing from reference data list." << std::endl;
  DataVectorType v;

  for (DataVectorType::iterator dataIter = m_WorkingData.begin(); dataIter != m_WorkingData.end(); ++dataIter )
  {
    //std::cout << " In list: " << (void*)(*dataIter);
    if ( (void*)(*dataIter) != (void*)caller )
    {
      v.push_back( *dataIter );
      //std::cout << " kept" << std::endl;
    }
    else
    {
      //std::cout << " removed" << std::endl;
      m_WorkingDataObserverTags.erase( *dataIter ); // no tag to remove anymore
    }
  }
  this->SetWorkingData( v );
}


void mitk::ToolManager::SetWorkingData(DataTreeNode* data)
{
  DataVectorType v;

  if (data) // don't allow for NULL nodes
  {
    v.push_back(data);
  }

  SetWorkingData(v);
}

mitk::ToolManager::DataVectorType mitk::ToolManager::GetReferenceData()
{
  return m_ReferenceData;
}

mitk::DataTreeNode* mitk::ToolManager::GetReferenceData(int idx)
{
  try
  {
    return m_ReferenceData.at(idx);
  }
  catch(std::exception&)
  {
    return NULL;
  }
}

mitk::ToolManager::DataVectorType mitk::ToolManager::GetWorkingData()
{
  return m_WorkingData;
}

mitk::DataTreeNode* mitk::ToolManager::GetWorkingData(int idx)
{
  try
  {
    return m_WorkingData.at(idx);
  }
  catch(std::exception&)
  {
    return NULL;
  }
}
    
int mitk::ToolManager::GetActiveToolID()
{
  return m_ActiveToolID;
}

mitk::Tool* mitk::ToolManager::GetActiveTool()
{
  return m_ActiveTool;
}

void mitk::ToolManager::RegisterClient()
{
  if ( m_RegisteredClients == 0 )
  {
    if ( m_ActiveTool )
    {
      m_ActiveTool->Activated();
      mitk::GlobalInteraction::GetInstance()->AddListener( m_ActiveTool );
    }
  }
  
  ++m_RegisteredClients;
}

void mitk::ToolManager::UnregisterClient()
{
  --m_RegisteredClients;

  if ( m_RegisteredClients == 0 )
  {
    if ( m_ActiveTool )
    {
      m_ActiveTool->Deactivated();
      mitk::GlobalInteraction::GetInstance()->RemoveListener( m_ActiveTool );
    }
  }
}


