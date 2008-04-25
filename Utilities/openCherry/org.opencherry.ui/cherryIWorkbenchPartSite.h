/*=========================================================================
 
Program:   openCherry Platform
Language:  C++
Date:      $Date$
Version:   $Revision$
 
Copyright (c) German Cancer Research Center, Division of Medical and
Biological Informatics. All rights reserved.
See MITKCopyright.txt or http://www.mitk.org/copyright.html for details.
 
This software is distributed WITHOUT ANY WARRANTY; without even
the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the above copyright notices for more information.
 
=========================================================================*/

#ifndef IWORKBENCHPARTSITE_H_
#define IWORKBENCHPARTSITE_H_


#include "cherryIWorkbenchSite.h"

namespace cherry {

struct IWorkbenchPart;

/**
 * The primary interface between a workbench part and the workbench.
 * <p>
 * This interface is not intended to be implemented or extended by clients.
 * </p>
 * @noimplement This interface is not intended to be implemented by clients.
 */
struct CHERRY_UI IWorkbenchPartSite : public IWorkbenchSite
{
  
  cherryClassMacro(IWorkbenchPartSite);
  
  /**
   * Returns the part registry extension id for this workbench site's part.
   * <p>
   * The name comes from the <code>id</code> attribute in the configuration
   * element.
   * </p>
   *
   * @return the registry extension id
   */
  virtual std::string GetId() = 0;
  
  /**
   * Returns the part associated with this site 
   *
   * @return the part associated with this site
   */
  virtual SmartPointer<IWorkbenchPart> GetPart() = 0;
  
  /**
   * Returns the unique identifier of the plug-in that defines this workbench
   * site's part.
   *
   * @return the unique identifier of the declaring plug-in
   */
  virtual std::string GetPluginId() = 0;
  
  /**
   * Returns the registered name for this workbench site's part.
   * <p>
   * The name comes from the <code>name</code> attribute in the configuration
   * element.
   * </p>
   *
   * @return the part name
   */
  virtual std::string GetRegisteredName() = 0;
  
};

} // namespace cherry


#endif /*IWORKBENCHPARTSITE_H_*/
