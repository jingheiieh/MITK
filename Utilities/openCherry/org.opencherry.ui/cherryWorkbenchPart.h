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

#ifndef __CHERRY_WORKBENCH_PART_H__
#define __CHERRY_WORKBENCH_PART_H__

#include "cherryIWorkbenchPart.h"
#include "cherryIWorkbenchPartSite.h"

#include <QtCore/QString>
#include <QtGui/QIcon>
#include <QtGui/QWidget>


namespace cherry {

/**
 * Abstract base implementation of all workbench parts.
 * <p>
 * This class is not intended to be subclassed by clients outside this
 * package; clients should instead subclass <code>ViewPart</code> or
 * <code>EditorPart</code>.
 * </p>
 * 
 * @see org.eclipse.ui.part.ViewPart
 * @see org.eclipse.ui.part.EditorPart
 * @noextend This class is not intended to be subclassed by clients.
 */
class CHERRY_UI WorkbenchPart : public virtual IWorkbenchPart
{
  
public:
  cherryClassMacro(WorkbenchPart);
  
private:
  std::string m_Title;
  //ImageDescriptor m_ImageDescriptor;
  void* m_TitleImage;
  std::string m_ToolTip;

  //IConfigurationElement::Pointer m_ConfigElement;
  IWorkbenchPartSite::Pointer m_PartSite;
  std::string m_PartName;
  std::string m_ContentDescription;
  //ListenerList m_PartChangeListeners = new ListenerList();

  void InternalSetContentDescription(const std::string& description);
  void InternalSetPartName(const std::string& partName);
  
protected:
  WorkbenchPart();
  
  /**
    * Returns the configuration element for this part. The configuration element
    * comes from the plug-in registry entry for the extension defining this part.
    *
    * @return the configuration element for this part
    */
//  IConfigurationElement* GetConfigurationElement() 
//  {
//    return m_ConfigElement;
//  }
  
  /**
    * Returns the default title image.
    *
    * @return the default image
    */
//  protected Image getDefaultImage() {
//    return PlatformUI.getWorkbench().getSharedImages().getImage(
//                ISharedImages.IMG_DEF_VIEW);
//  }
  
  /**
   * Sets the part site.
   * <p>
   * Subclasses must invoke this method from <code>IEditorPart.init</code>
   * and <code>IViewPart.init</code>.
   *
   * @param site the workbench part site
   */
  void SetSite(IWorkbenchPartSite::Pointer site);
  
  /**
   * Checks that the given site is valid for this type of part.
   * The default implementation does nothing.
   * 
   * @param site the site to check
   */
  virtual void CheckSite(IWorkbenchPartSite::Pointer site);
  
  /**
   * Sets or clears the title image of this part.
   *
   * @param titleImage the title image, or <code>null</code> to clear
   */
  virtual void SetTitleImage(void* titleImage);

  /**
   * Sets or clears the title tool tip text of this part. Clients should
   * call this method instead of overriding <code>getTitleToolTip</code>
   *
   * @param toolTip the new tool tip text, or <code>null</code> to clear
   */
  virtual void SetTitleToolTip(const std::string& toolTip);
  
  /**
   * Sets the name of this part. The name will be shown in the tab area for 
   * the part. Clients should call this method instead of overriding getPartName.
   * Setting this to the empty string will cause a default part name to be used.
   *
   * @param partName the part name, as it should be displayed in tabs.
   */
  virtual void SetPartName(const std::string& partName);
  
  /**
   * Sets the content description for this part. The content description is typically
   * a short string describing the current contents of the part. Setting this to the
   * empty string will cause a default content description to be used. Clients should
   * call this method instead of overriding getContentDescription(). For views, the
   * content description is shown (by default) in a line near the top of the view. For
   * editors, the content description is shown beside the part name when showing a
   * list of editors. If the editor is open on a file, this typically contains the path 
   * to the input file, without the filename or trailing slash.
   * 
   * @param description the content description
   */
  virtual void SetContentDescription(const std::string& description);


public:
  /* 
   * Creates the Qt controls for this workbench part.
   * <p>
   * Subclasses must implement this method.  For a detailed description of the
   * requirements see <code>IWorkbenchPart</code>
   * </p>
   *
   * @param parent the parent control
   * @see IWorkbenchPart
   */
  virtual void* CreatePartControl(void* parent) = 0;
  
  /* (non-Javadoc)
     * Asks this part to take focus within the workbench.
     * <p>
     * Subclasses must implement this method.  For a detailed description of the
     * requirements see <code>IWorkbenchPart</code>
     * </p>
     *
     * @see IWorkbenchPart
     */
  virtual void SetFocus() = 0;
  
  /* 
   * Method declared on IWorkbenchPart.
   */
  IWorkbenchPartSite::Pointer GetSite();

  /**
   * {@inheritDoc}
   * <p>
   * It is considered bad practise to overload or extend this method.
   * Parts should call setPartName to change their part name. 
   * </p>
   */
  std::string GetPartName();

  /**
   * {@inheritDoc}
   * <p>
   * It is considered bad practise to overload or extend this method.
   * Parts should call setContentDescription to change their content description. 
   * </p>
   */
  std::string GetContentDescription();


  /* (non-Javadoc)
   * Method declared on IWorkbenchPart.
   */
  void* GetTitleImage();

  /* (non-Javadoc)
   * Gets the title tool tip text of this part.
   *
   * @return the tool tip text
   */
  std::string GetTitleToolTip();
  
};

} // namespace cherry

#endif // __CHERRY_WORKBENCH_PART_H__

