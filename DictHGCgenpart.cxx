// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGCgenpart

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "inc/HGCgenpart.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGCgenpart(void *p = 0);
   static void *newArray_HGCgenpart(Long_t size, void *p);
   static void delete_HGCgenpart(void *p);
   static void deleteArray_HGCgenpart(void *p);
   static void destruct_HGCgenpart(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGCgenpart*)
   {
      ::HGCgenpart *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGCgenpart >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGCgenpart", ::HGCgenpart::Class_Version(), "inc/HGCgenpart.h", 23,
                  typeid(::HGCgenpart), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGCgenpart::Dictionary, isa_proxy, 4,
                  sizeof(::HGCgenpart) );
      instance.SetNew(&new_HGCgenpart);
      instance.SetNewArray(&newArray_HGCgenpart);
      instance.SetDelete(&delete_HGCgenpart);
      instance.SetDeleteArray(&deleteArray_HGCgenpart);
      instance.SetDestructor(&destruct_HGCgenpart);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGCgenpart*)
   {
      return GenerateInitInstanceLocal((::HGCgenpart*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGCgenpart*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGCgenpart::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGCgenpart::Class_Name()
{
   return "HGCgenpart";
}

//______________________________________________________________________________
const char *HGCgenpart::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCgenpart*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGCgenpart::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCgenpart*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGCgenpart::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCgenpart*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGCgenpart::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCgenpart*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGCgenpart::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGCgenpart.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGCgenpart::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGCgenpart::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGCgenpart(void *p) {
      return  p ? new(p) ::HGCgenpart : new ::HGCgenpart;
   }
   static void *newArray_HGCgenpart(Long_t nElements, void *p) {
      return p ? new(p) ::HGCgenpart[nElements] : new ::HGCgenpart[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGCgenpart(void *p) {
      delete ((::HGCgenpart*)p);
   }
   static void deleteArray_HGCgenpart(void *p) {
      delete [] ((::HGCgenpart*)p);
   }
   static void destruct_HGCgenpart(void *p) {
      typedef ::HGCgenpart current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGCgenpart

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 447,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGCgenpartgR_Dictionary();
   static void maplEunsignedsPintcOHGCgenpartgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCgenpartgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCgenpartgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCgenpartgR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCgenpartgR(void *p);
   static void destruct_maplEunsignedsPintcOHGCgenpartgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCgenpart>*)
   {
      map<unsigned int,HGCgenpart> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCgenpart>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCgenpart>", -2, "map", 805,
                  typeid(map<unsigned int,HGCgenpart>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCgenpartgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGCgenpart>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCgenpartgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCgenpartgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCgenpartgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCgenpartgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCgenpartgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCgenpart> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCgenpart>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCgenpartgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCgenpart>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCgenpartgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCgenpartgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCgenpartgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgenpart> : new map<unsigned int,HGCgenpart>;
   }
   static void *newArray_maplEunsignedsPintcOHGCgenpartgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgenpart>[nElements] : new map<unsigned int,HGCgenpart>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCgenpartgR(void *p) {
      delete ((map<unsigned int,HGCgenpart>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCgenpartgR(void *p) {
      delete [] ((map<unsigned int,HGCgenpart>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCgenpartgR(void *p) {
      typedef map<unsigned int,HGCgenpart> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCgenpart>

namespace ROOT {
   static TClass *maplEintcOHGCgenpartgR_Dictionary();
   static void maplEintcOHGCgenpartgR_TClassManip(TClass*);
   static void *new_maplEintcOHGCgenpartgR(void *p = 0);
   static void *newArray_maplEintcOHGCgenpartgR(Long_t size, void *p);
   static void delete_maplEintcOHGCgenpartgR(void *p);
   static void deleteArray_maplEintcOHGCgenpartgR(void *p);
   static void destruct_maplEintcOHGCgenpartgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<int,HGCgenpart>*)
   {
      map<int,HGCgenpart> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<int,HGCgenpart>));
      static ::ROOT::TGenericClassInfo 
         instance("map<int,HGCgenpart>", -2, "map", 805,
                  typeid(map<int,HGCgenpart>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEintcOHGCgenpartgR_Dictionary, isa_proxy, 4,
                  sizeof(map<int,HGCgenpart>) );
      instance.SetNew(&new_maplEintcOHGCgenpartgR);
      instance.SetNewArray(&newArray_maplEintcOHGCgenpartgR);
      instance.SetDelete(&delete_maplEintcOHGCgenpartgR);
      instance.SetDeleteArray(&deleteArray_maplEintcOHGCgenpartgR);
      instance.SetDestructor(&destruct_maplEintcOHGCgenpartgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<int,HGCgenpart> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<int,HGCgenpart>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEintcOHGCgenpartgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<int,HGCgenpart>*)0x0)->GetClass();
      maplEintcOHGCgenpartgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEintcOHGCgenpartgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEintcOHGCgenpartgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCgenpart> : new map<int,HGCgenpart>;
   }
   static void *newArray_maplEintcOHGCgenpartgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<int,HGCgenpart>[nElements] : new map<int,HGCgenpart>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEintcOHGCgenpartgR(void *p) {
      delete ((map<int,HGCgenpart>*)p);
   }
   static void deleteArray_maplEintcOHGCgenpartgR(void *p) {
      delete [] ((map<int,HGCgenpart>*)p);
   }
   static void destruct_maplEintcOHGCgenpartgR(void *p) {
      typedef map<int,HGCgenpart> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<int,HGCgenpart>

namespace {
  void TriggerDictionaryInitialization_DictHGCgenpart_Impl() {
    static const char* headers[] = {
"inc/HGCgenpart.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/yoyo/Documents/Project/dev/HGC-CMSSW-ANLYSIS/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGCgenpart dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$inc/HGCgenpart.h")))  HGCgenpart;
namespace std{inline namespace __1{template <class _Tp> struct __attribute__((annotate("$clingAutoload$__functional_base")))  __attribute__((annotate("$clingAutoload$string")))  less;
}}
namespace std{inline namespace __1{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$utility")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}}
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$memory")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGCgenpart dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGCgenpart.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGCgenpart", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGCgenpart",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGCgenpart_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGCgenpart_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGCgenpart() {
  TriggerDictionaryInitialization_DictHGCgenpart_Impl();
}
