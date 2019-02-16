// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGCC2D

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
#include "inc/HGCC2D.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGCC2D(void *p = 0);
   static void *newArray_HGCC2D(Long_t size, void *p);
   static void delete_HGCC2D(void *p);
   static void deleteArray_HGCC2D(void *p);
   static void destruct_HGCC2D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGCC2D*)
   {
      ::HGCC2D *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGCC2D >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGCC2D", ::HGCC2D::Class_Version(), "inc/HGCC2D.h", 24,
                  typeid(::HGCC2D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGCC2D::Dictionary, isa_proxy, 4,
                  sizeof(::HGCC2D) );
      instance.SetNew(&new_HGCC2D);
      instance.SetNewArray(&newArray_HGCC2D);
      instance.SetDelete(&delete_HGCC2D);
      instance.SetDeleteArray(&deleteArray_HGCC2D);
      instance.SetDestructor(&destruct_HGCC2D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGCC2D*)
   {
      return GenerateInitInstanceLocal((::HGCC2D*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGCC2D*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGCC2D::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGCC2D::Class_Name()
{
   return "HGCC2D";
}

//______________________________________________________________________________
const char *HGCC2D::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCC2D*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGCC2D::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCC2D*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGCC2D::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCC2D*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGCC2D::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCC2D*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGCC2D::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGCC2D.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGCC2D::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGCC2D::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGCC2D(void *p) {
      return  p ? new(p) ::HGCC2D : new ::HGCC2D;
   }
   static void *newArray_HGCC2D(Long_t nElements, void *p) {
      return p ? new(p) ::HGCC2D[nElements] : new ::HGCC2D[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGCC2D(void *p) {
      delete ((::HGCC2D*)p);
   }
   static void deleteArray_HGCC2D(void *p) {
      delete [] ((::HGCC2D*)p);
   }
   static void destruct_HGCC2D(void *p) {
      typedef ::HGCC2D current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGCC2D

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 447,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEHGCC2DgR_Dictionary();
   static void vectorlEHGCC2DgR_TClassManip(TClass*);
   static void *new_vectorlEHGCC2DgR(void *p = 0);
   static void *newArray_vectorlEHGCC2DgR(Long_t size, void *p);
   static void delete_vectorlEHGCC2DgR(void *p);
   static void deleteArray_vectorlEHGCC2DgR(void *p);
   static void destruct_vectorlEHGCC2DgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCC2D>*)
   {
      vector<HGCC2D> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCC2D>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCC2D>", -2, "vector", 447,
                  typeid(vector<HGCC2D>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCC2DgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HGCC2D>) );
      instance.SetNew(&new_vectorlEHGCC2DgR);
      instance.SetNewArray(&newArray_vectorlEHGCC2DgR);
      instance.SetDelete(&delete_vectorlEHGCC2DgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCC2DgR);
      instance.SetDestructor(&destruct_vectorlEHGCC2DgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCC2D> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCC2D>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCC2DgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCC2D>*)0x0)->GetClass();
      vectorlEHGCC2DgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCC2DgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCC2DgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC2D> : new vector<HGCC2D>;
   }
   static void *newArray_vectorlEHGCC2DgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC2D>[nElements] : new vector<HGCC2D>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCC2DgR(void *p) {
      delete ((vector<HGCC2D>*)p);
   }
   static void deleteArray_vectorlEHGCC2DgR(void *p) {
      delete [] ((vector<HGCC2D>*)p);
   }
   static void destruct_vectorlEHGCC2DgR(void *p) {
      typedef vector<HGCC2D> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCC2D>

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGCC2DgR_Dictionary();
   static void maplEunsignedsPintcOHGCC2DgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCC2DgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCC2DgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCC2DgR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCC2DgR(void *p);
   static void destruct_maplEunsignedsPintcOHGCC2DgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCC2D>*)
   {
      map<unsigned int,HGCC2D> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCC2D>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCC2D>", -2, "map", 805,
                  typeid(map<unsigned int,HGCC2D>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCC2DgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGCC2D>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCC2DgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCC2DgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCC2DgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCC2DgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCC2DgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCC2D> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCC2D>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCC2DgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCC2D>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCC2DgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCC2DgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCC2DgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCC2D> : new map<unsigned int,HGCC2D>;
   }
   static void *newArray_maplEunsignedsPintcOHGCC2DgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCC2D>[nElements] : new map<unsigned int,HGCC2D>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCC2DgR(void *p) {
      delete ((map<unsigned int,HGCC2D>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCC2DgR(void *p) {
      delete [] ((map<unsigned int,HGCC2D>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCC2DgR(void *p) {
      typedef map<unsigned int,HGCC2D> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCC2D>

namespace {
  void TriggerDictionaryInitialization_DictHGCC2D_Impl() {
    static const char* headers[] = {
"inc/HGCC2D.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/yoyo/Documents/Project/dev/HGC-CMSSW-ANLYSIS/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGCC2D dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{inline namespace __1{template <class _Tp> class __attribute__((annotate("$clingAutoload$iosfwd")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}}
class __attribute__((annotate("$clingAutoload$inc/HGCC2D.h")))  HGCC2D;
namespace std{inline namespace __1{template <class _Tp> struct __attribute__((annotate("$clingAutoload$__functional_base")))  __attribute__((annotate("$clingAutoload$string")))  less;
}}
namespace std{inline namespace __1{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$utility")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGCC2D dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGCC2D.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGCC2D", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGCC2D",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGCC2D_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGCC2D_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGCC2D() {
  TriggerDictionaryInitialization_DictHGCC2D_Impl();
}
