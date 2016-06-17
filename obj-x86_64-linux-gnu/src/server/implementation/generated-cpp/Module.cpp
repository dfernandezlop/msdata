/* Autogenerated with kurento-module-creator */

#include "FactoryRegistrar.hpp"

#include <KmsMsDataImplFactory.hpp>
#include <KmsMsData.hpp>

extern "C" {

  const kurento::FactoryRegistrar *getFactoryRegistrar ();

}

const kurento::FactoryRegistrar *
getFactoryRegistrar ()
{
  static bool loaded = false;
  static std::map<std::string, std::shared_ptr<kurento::Factory>> factories;

  if (!loaded) {
    factories["KmsMsData"] = std::shared_ptr <kurento::Factory> (new kurento::module::msdata::KmsMsDataImplFactory() );

    loaded = true;
  }

  static kurento::FactoryRegistrar factory (factories);
  return &factory;
}
