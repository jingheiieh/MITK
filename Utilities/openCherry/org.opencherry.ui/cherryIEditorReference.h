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

#ifndef CHERRYIEDITORREFERENCE_H_
#define CHERRYIEDITORREFERENCE_H_

#include "cherryIWorkbenchPartReference.h"
#include "cherryIEditorPart.h"
#include "cherryIEditorInput.h"

namespace cherry {

/**
 * Implements a reference to a editor.
 * The IEditorPart will not be instanciated until
 * the editor becomes visible or the API getEditor
 * is sent with true;
 * <p>
 * This interface is not intended to be implemented by clients.
 * </p>
 */
struct CHERRY_UI IEditorReference : public IWorkbenchPartReference {
  
  cherryClassMacro(IEditorReference);
  
    /**
     * Returns the factory id of the factory used to 
     * restore this editor. Returns null if the editor
     * is not persistable.
     */
    virtual std::string GetFactoryId() = 0;

    /**
     * Returns the editor input name. May return null is the
     * name is not available or if the editor failed to be 
     * restored.
     */
    virtual std::string GetName() = 0;

    /**
     * Returns the editor referenced by this object.
     * Returns <code>null</code> if the editor was not instantiated or
     * it failed to be restored. Tries to restore the editor
     * if <code>restore</code> is true.
     */
    virtual IEditorPart::Pointer GetEditor(bool restore) = 0;

    /**
     * Returns true if the editor is pinned otherwise returns false.
     */
    virtual bool IsPinned() = 0;

    /**
     * Returns the editor input for the editor referenced by this object.
     * <p>
     * Unlike most of the other methods on this type, this method
     * can trigger plug-in activation.
     * </p>
     *  
     * @return the editor input for the editor referenced by this object
     * @throws PartInitException if there was an error restoring the editor input
     * @since 3.1
     */
    virtual IEditorInput::Pointer GetEditorInput() = 0;
};

} // namespace cherry

#endif /*CHERRYIEDITORREFERENCE_H_*/
