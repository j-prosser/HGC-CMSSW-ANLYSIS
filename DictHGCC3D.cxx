// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGCC3D

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
#include "./inc/HGCC3D.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_HGCC3D(void *p = 0);
   static void *newArray_HGCC3D(Long_t size, void *p);
   static void delete_HGCC3D(void *p);
   static void deleteArray_HGCC3D(void *p);
   static void destruct_HGCC3D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGCC3D*)
   {
      ::HGCC3D *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGCC3D >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGCC3D", ::HGCC3D::Class_Version(), "inc/HGCC3D.h", 22,
                  typeid(::HGCC3D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGCC3D::Dictionary, isa_proxy, 4,
                  sizeof(::HGCC3D) );
      instance.SetNew(&new_HGCC3D);
      instance.SetNewArray(&newArray_HGCC3D);
      instance.SetDelete(&delete_HGCC3D);
      instance.SetDeleteArray(&deleteArray_HGCC3D);
      instance.SetDestructor(&destruct_HGCC3D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGCC3D*)
   {
      return GenerateInitInstanceLocal((::HGCC3D*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGCC3D*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGCC3D::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGCC3D::Class_Name()
{
   return "HGCC3D";
}

//______________________________________________________________________________
const char *HGCC3D::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCC3D*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGCC3D::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGCC3D*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGCC3D::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCC3D*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGCC3D::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGCC3D*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGCC3D::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGCC3D.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGCC3D::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGCC3D::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_HGCC3D(void *p) {
      return  p ? new(p) ::HGCC3D : new ::HGCC3D;
   }
   static void *newArray_HGCC3D(Long_t nElements, void *p) {
      return p ? new(p) ::HGCC3D[nElements] : new ::HGCC3D[nElements];
   }
   // Wrapper around operator delete
   static void delete_HGCC3D(void *p) {
      delete ((::HGCC3D*)p);
   }
   static void deleteArray_HGCC3D(void *p) {
      delete [] ((::HGCC3D*)p);
   }
   static void destruct_HGCC3D(void *p) {
      typedef ::HGCC3D current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGCC3D

namespace ROOT {
   static TClass *vectorlEvectorlEunsignedsPintgRsPgR_Dictionary();
   static void vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEunsignedsPintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEunsignedsPintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEunsignedsPintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEunsignedsPintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEunsignedsPintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<unsigned int> >*)
   {
      vector<vector<unsigned int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<unsigned int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<unsigned int> >", -2, "vector", 210,
                  typeid(vector<vector<unsigned int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEunsignedsPintgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<unsigned int> >) );
      instance.SetNew(&new_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEunsignedsPintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<unsigned int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<unsigned int> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEunsignedsPintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<unsigned int> >*)0x0)->GetClass();
      vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEunsignedsPintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<unsigned int> > : new vector<vector<unsigned int> >;
   }
   static void *newArray_vectorlEvectorlEunsignedsPintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<unsigned int> >[nElements] : new vector<vector<unsigned int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      delete ((vector<vector<unsigned int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      delete [] ((vector<vector<unsigned int> >*)p);
   }
   static void destruct_vectorlEvectorlEunsignedsPintgRsPgR(void *p) {
      typedef vector<vector<unsigned int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<unsigned int> >

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
         instance("vector<unsigned int>", -2, "vector", 210,
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
   static TClass *vectorlEHGCC3DgR_Dictionary();
   static void vectorlEHGCC3DgR_TClassManip(TClass*);
   static void *new_vectorlEHGCC3DgR(void *p = 0);
   static void *newArray_vectorlEHGCC3DgR(Long_t size, void *p);
   static void delete_vectorlEHGCC3DgR(void *p);
   static void deleteArray_vectorlEHGCC3DgR(void *p);
   static void destruct_vectorlEHGCC3DgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCC3D>*)
   {
      vector<HGCC3D> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCC3D>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCC3D>", -2, "vector", 210,
                  typeid(vector<HGCC3D>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCC3DgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HGCC3D>) );
      instance.SetNew(&new_vectorlEHGCC3DgR);
      instance.SetNewArray(&newArray_vectorlEHGCC3DgR);
      instance.SetDelete(&delete_vectorlEHGCC3DgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCC3DgR);
      instance.SetDestructor(&destruct_vectorlEHGCC3DgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCC3D> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCC3D>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCC3DgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCC3D>*)0x0)->GetClass();
      vectorlEHGCC3DgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCC3DgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCC3DgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC3D> : new vector<HGCC3D>;
   }
   static void *newArray_vectorlEHGCC3DgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC3D>[nElements] : new vector<HGCC3D>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCC3DgR(void *p) {
      delete ((vector<HGCC3D>*)p);
   }
   static void deleteArray_vectorlEHGCC3DgR(void *p) {
      delete [] ((vector<HGCC3D>*)p);
   }
   static void destruct_vectorlEHGCC3DgR(void *p) {
      typedef vector<HGCC3D> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCC3D>

namespace ROOT {
   static TClass *vectorlEHGCC3DmUgR_Dictionary();
   static void vectorlEHGCC3DmUgR_TClassManip(TClass*);
   static void *new_vectorlEHGCC3DmUgR(void *p = 0);
   static void *newArray_vectorlEHGCC3DmUgR(Long_t size, void *p);
   static void delete_vectorlEHGCC3DmUgR(void *p);
   static void deleteArray_vectorlEHGCC3DmUgR(void *p);
   static void destruct_vectorlEHGCC3DmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCC3D*>*)
   {
      vector<HGCC3D*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCC3D*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCC3D*>", -2, "vector", 210,
                  typeid(vector<HGCC3D*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCC3DmUgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<HGCC3D*>) );
      instance.SetNew(&new_vectorlEHGCC3DmUgR);
      instance.SetNewArray(&newArray_vectorlEHGCC3DmUgR);
      instance.SetDelete(&delete_vectorlEHGCC3DmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCC3DmUgR);
      instance.SetDestructor(&destruct_vectorlEHGCC3DmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCC3D*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCC3D*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCC3DmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCC3D*>*)0x0)->GetClass();
      vectorlEHGCC3DmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCC3DmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCC3DmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC3D*> : new vector<HGCC3D*>;
   }
   static void *newArray_vectorlEHGCC3DmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCC3D*>[nElements] : new vector<HGCC3D*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCC3DmUgR(void *p) {
      delete ((vector<HGCC3D*>*)p);
   }
   static void deleteArray_vectorlEHGCC3DmUgR(void *p) {
      delete [] ((vector<HGCC3D*>*)p);
   }
   static void destruct_vectorlEHGCC3DmUgR(void *p) {
      typedef vector<HGCC3D*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCC3D*>

namespace ROOT {
   static TClass *maplEunsignedsPintcOHGCC3DgR_Dictionary();
   static void maplEunsignedsPintcOHGCC3DgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCC3DgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCC3DgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCC3DgR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCC3DgR(void *p);
   static void destruct_maplEunsignedsPintcOHGCC3DgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCC3D>*)
   {
      map<unsigned int,HGCC3D> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCC3D>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCC3D>", -2, "map", 96,
                  typeid(map<unsigned int,HGCC3D>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCC3DgR_Dictionary, isa_proxy, 4,
                  sizeof(map<unsigned int,HGCC3D>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCC3DgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCC3DgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCC3DgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCC3DgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCC3DgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCC3D> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCC3D>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCC3DgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCC3D>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCC3DgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCC3DgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCC3DgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCC3D> : new map<unsigned int,HGCC3D>;
   }
   static void *newArray_maplEunsignedsPintcOHGCC3DgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCC3D>[nElements] : new map<unsigned int,HGCC3D>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCC3DgR(void *p) {
      delete ((map<unsigned int,HGCC3D>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCC3DgR(void *p) {
      delete [] ((map<unsigned int,HGCC3D>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCC3DgR(void *p) {
      typedef map<unsigned int,HGCC3D> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCC3D>

namespace {
  void TriggerDictionaryInitialization_DictHGCC3D_Impl() {
    static const char* headers[] = {
"./inc/HGCC3D.h",
0
    };
    static const char* includePaths[] = {
"/home/johannes/root/include",
"/home/johannes/HCA/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGCC3D dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$bits/allocator.h")))  __attribute__((annotate("$clingAutoload$string")))  allocator;
}
class __attribute__((annotate("$clingAutoload$./inc/HGCC3D.h")))  HGCC3D;
namespace std{template <typename _Tp> struct __attribute__((annotate("$clingAutoload$bits/stl_function.h")))  __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$bits/stl_pair.h")))  __attribute__((annotate("$clingAutoload$string")))  pair;
}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGCC3D dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "./inc/HGCC3D.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGCC3D", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGCC3D",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGCC3D_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGCC3D_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGCC3D() {
  TriggerDictionaryInitialization_DictHGCC3D_Impl();
}
