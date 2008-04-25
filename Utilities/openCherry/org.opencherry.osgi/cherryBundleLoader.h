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

#ifndef CHERRYBUNDLELOADER_H_
#define CHERRYBUNDLELOADER_H_

#include "Poco/ClassLoader.h"
#include "Poco/Mutex.h"
#include "Poco/Path.h"
#include "Poco/Any.h"
#include "Poco/SharedPtr.h"
#include "Poco/Logger.h"

#include <typeinfo>
#include <map>

#include "event/cherryBundleEvents.h"
#include "cherryIBundleActivator.h"
#include "cherryIBundleContext.h"

#include "internal/cherryBundle.h"
#include "internal/cherrySystemBundle.h"

namespace cherry {

class CodeCache;

/**
 * Intentionally no CHERRY_OSGI macro. This class belongs into "internal" but
 * needs to stay here.
 */
class BundleLoader
{

private:
  typedef Poco::ClassLoader<IBundleActivator> ActivatorClassLoader;
  typedef Poco::SharedPtr<ActivatorClassLoader> ActivatorClassLoaderPtr;
  
  struct BundleInfo {
    Bundle::Pointer m_Bundle;
    ActivatorClassLoaderPtr m_ClassLoader;
    std::map<std::string, Poco::Any*> m_ClassLoaderMap;
    IBundleContext::Pointer m_Context;
  };
  
  typedef std::map<std::string, BundleInfo> BundleMap;
  
  BundleMap m_BundleMap;
  BundleEvents m_BundleEvents;
  CodeCache* m_CodeCache;
  mutable Poco::Logger& m_Logger;
  
  Bundle::Pointer m_SystemBundle;
  
  mutable Poco::Mutex m_Mutex;
  
  IBundleActivator* LoadActivator(BundleInfo& bundleInfo);
  
  friend class InternalPlatform;
  void StartSystemBundle(SystemBundle* bundle);
  
public:
  BundleLoader(CodeCache* codeCache, Poco::Logger& logger); //, BundleFactory* bundleFactory, BundleContextFactory* bundleContextFactory);
  virtual ~BundleLoader();
  
  IBundleContext::Pointer GetContextForBundle(IBundle::ConstPointer bundle);
  Bundle::Pointer CreateBundle(const Poco::Path& path);
  
  BundleEvents& GetEvents();
  IBundle::Pointer FindBundle(const std::string& symbolicName);
  
  Bundle::Pointer LoadBundle(const Poco::Path& path);
  void LoadBundle(Bundle::Pointer bundle);
  
  Poco::Path GetPathForLibrary(const std::string& libraryName);
  Poco::Path GetLibraryPathFor(IBundle* bundle);
  std::string GetContributionsPathFor(IBundle* bundle);
  
  Poco::Logger& GetLogger() const;
  
  void ResolveBundle(IBundle* bundle);
  void ResolveAllBundles();
  
  void ReadAllContributions();
  void ReadContributions(IBundle* bundle);
  void ReadDependentContributions(IBundle* bundle);
  
  void ListLibraries(IBundle* bundle, std::vector<std::string>& list);
  void InstallLibraries(IBundle* bundle);
  
  // start all resolved bundles, except the system bundle
  // (it is assumed, that the system bundle has already
  //  been started)
  void StartAllBundles();
  void StartBundle(Bundle* bundle);
  void StartDependencies(Bundle* bundle);
  
  template<class C>
  C* LoadClass(const std::string& bundleName, const std::string& base,
                 const std::string& className);

  
};

}  // namespace cherry

#include "cherryBundleLoader.txx"

#endif /*CHERRYBUNDLELOADER_H_*/
