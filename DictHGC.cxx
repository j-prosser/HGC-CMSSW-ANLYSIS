// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME DictHGC

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
#include "inc/HGC.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void delete_HGC(void *p);
   static void deleteArray_HGC(void *p);
   static void destruct_HGC(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::HGC*)
   {
      ::HGC *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::HGC >(0);
      static ::ROOT::TGenericClassInfo 
         instance("HGC", ::HGC::Class_Version(), "inc/HGC.h", 25,
                  typeid(::HGC), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::HGC::Dictionary, isa_proxy, 4,
                  sizeof(::HGC) );
      instance.SetDelete(&delete_HGC);
      instance.SetDeleteArray(&deleteArray_HGC);
      instance.SetDestructor(&destruct_HGC);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::HGC*)
   {
      return GenerateInitInstanceLocal((::HGC*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::HGC*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr HGC::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *HGC::Class_Name()
{
   return "HGC";
}

//______________________________________________________________________________
const char *HGC::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGC*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int HGC::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::HGC*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *HGC::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGC*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *HGC::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::HGC*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void HGC::Streamer(TBuffer &R__b)
{
   // Stream an object of class HGC.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(HGC::Class(),this);
   } else {
      R__b.WriteClassBuffer(HGC::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_HGC(void *p) {
      delete ((::HGC*)p);
   }
   static void deleteArray_HGC(void *p) {
      delete [] ((::HGC*)p);
   }
   static void destruct_HGC(void *p) {
      typedef ::HGC current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::HGC

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
         instance("vector<vector<unsigned int> >", -2, "vector", 447,
                  typeid(vector<vector<unsigned int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEunsignedsPintgRsPgR_Dictionary, isa_proxy, 0,
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
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 447,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

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
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
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
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 447,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

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
   static TClass *vectorlEboolgR_Dictionary();
   static void vectorlEboolgR_TClassManip(TClass*);
   static void *new_vectorlEboolgR(void *p = 0);
   static void *newArray_vectorlEboolgR(Long_t size, void *p);
   static void delete_vectorlEboolgR(void *p);
   static void deleteArray_vectorlEboolgR(void *p);
   static void destruct_vectorlEboolgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<bool>*)
   {
      vector<bool> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<bool>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<bool>", -2, "vector", 2148,
                  typeid(vector<bool>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEboolgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<bool>) );
      instance.SetNew(&new_vectorlEboolgR);
      instance.SetNewArray(&newArray_vectorlEboolgR);
      instance.SetDelete(&delete_vectorlEboolgR);
      instance.SetDeleteArray(&deleteArray_vectorlEboolgR);
      instance.SetDestructor(&destruct_vectorlEboolgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<bool> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<bool>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEboolgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<bool>*)0x0)->GetClass();
      vectorlEboolgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEboolgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEboolgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool> : new vector<bool>;
   }
   static void *newArray_vectorlEboolgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<bool>[nElements] : new vector<bool>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEboolgR(void *p) {
      delete ((vector<bool>*)p);
   }
   static void deleteArray_vectorlEboolgR(void *p) {
      delete [] ((vector<bool>*)p);
   }
   static void destruct_vectorlEboolgR(void *p) {
      typedef vector<bool> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<bool>

namespace ROOT {
   static TClass *vectorlEHGCgenpartmUgR_Dictionary();
   static void vectorlEHGCgenpartmUgR_TClassManip(TClass*);
   static void *new_vectorlEHGCgenpartmUgR(void *p = 0);
   static void *newArray_vectorlEHGCgenpartmUgR(Long_t size, void *p);
   static void delete_vectorlEHGCgenpartmUgR(void *p);
   static void deleteArray_vectorlEHGCgenpartmUgR(void *p);
   static void destruct_vectorlEHGCgenpartmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCgenpart*>*)
   {
      vector<HGCgenpart*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCgenpart*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCgenpart*>", -2, "vector", 447,
                  typeid(vector<HGCgenpart*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCgenpartmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<HGCgenpart*>) );
      instance.SetNew(&new_vectorlEHGCgenpartmUgR);
      instance.SetNewArray(&newArray_vectorlEHGCgenpartmUgR);
      instance.SetDelete(&delete_vectorlEHGCgenpartmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCgenpartmUgR);
      instance.SetDestructor(&destruct_vectorlEHGCgenpartmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCgenpart*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCgenpart*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCgenpartmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCgenpart*>*)0x0)->GetClass();
      vectorlEHGCgenpartmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCgenpartmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCgenpartmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgenpart*> : new vector<HGCgenpart*>;
   }
   static void *newArray_vectorlEHGCgenpartmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgenpart*>[nElements] : new vector<HGCgenpart*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCgenpartmUgR(void *p) {
      delete ((vector<HGCgenpart*>*)p);
   }
   static void deleteArray_vectorlEHGCgenpartmUgR(void *p) {
      delete [] ((vector<HGCgenpart*>*)p);
   }
   static void destruct_vectorlEHGCgenpartmUgR(void *p) {
      typedef vector<HGCgenpart*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCgenpart*>

namespace ROOT {
   static TClass *vectorlEHGCgenmUgR_Dictionary();
   static void vectorlEHGCgenmUgR_TClassManip(TClass*);
   static void *new_vectorlEHGCgenmUgR(void *p = 0);
   static void *newArray_vectorlEHGCgenmUgR(Long_t size, void *p);
   static void delete_vectorlEHGCgenmUgR(void *p);
   static void deleteArray_vectorlEHGCgenmUgR(void *p);
   static void destruct_vectorlEHGCgenmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<HGCgen*>*)
   {
      vector<HGCgen*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<HGCgen*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<HGCgen*>", -2, "vector", 447,
                  typeid(vector<HGCgen*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEHGCgenmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<HGCgen*>) );
      instance.SetNew(&new_vectorlEHGCgenmUgR);
      instance.SetNewArray(&newArray_vectorlEHGCgenmUgR);
      instance.SetDelete(&delete_vectorlEHGCgenmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlEHGCgenmUgR);
      instance.SetDestructor(&destruct_vectorlEHGCgenmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<HGCgen*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const vector<HGCgen*>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEHGCgenmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<HGCgen*>*)0x0)->GetClass();
      vectorlEHGCgenmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEHGCgenmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEHGCgenmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen*> : new vector<HGCgen*>;
   }
   static void *newArray_vectorlEHGCgenmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<HGCgen*>[nElements] : new vector<HGCgen*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEHGCgenmUgR(void *p) {
      delete ((vector<HGCgen*>*)p);
   }
   static void deleteArray_vectorlEHGCgenmUgR(void *p) {
      delete [] ((vector<HGCgen*>*)p);
   }
   static void destruct_vectorlEHGCgenmUgR(void *p) {
      typedef vector<HGCgen*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<HGCgen*>

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
                  &maplEunsignedsPintcOHGCgenpartgR_Dictionary, isa_proxy, 0,
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
   static TClass *maplEunsignedsPintcOHGCgengR_Dictionary();
   static void maplEunsignedsPintcOHGCgengR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOHGCgengR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOHGCgengR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOHGCgengR(void *p);
   static void deleteArray_maplEunsignedsPintcOHGCgengR(void *p);
   static void destruct_maplEunsignedsPintcOHGCgengR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,HGCgen>*)
   {
      map<unsigned int,HGCgen> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,HGCgen>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,HGCgen>", -2, "map", 805,
                  typeid(map<unsigned int,HGCgen>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOHGCgengR_Dictionary, isa_proxy, 0,
                  sizeof(map<unsigned int,HGCgen>) );
      instance.SetNew(&new_maplEunsignedsPintcOHGCgengR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOHGCgengR);
      instance.SetDelete(&delete_maplEunsignedsPintcOHGCgengR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOHGCgengR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOHGCgengR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,HGCgen> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const map<unsigned int,HGCgen>*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOHGCgengR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,HGCgen>*)0x0)->GetClass();
      maplEunsignedsPintcOHGCgengR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOHGCgengR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOHGCgengR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgen> : new map<unsigned int,HGCgen>;
   }
   static void *newArray_maplEunsignedsPintcOHGCgengR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,HGCgen>[nElements] : new map<unsigned int,HGCgen>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOHGCgengR(void *p) {
      delete ((map<unsigned int,HGCgen>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOHGCgengR(void *p) {
      delete [] ((map<unsigned int,HGCgen>*)p);
   }
   static void destruct_maplEunsignedsPintcOHGCgengR(void *p) {
      typedef map<unsigned int,HGCgen> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,HGCgen>

namespace {
  void TriggerDictionaryInitialization_DictHGC_Impl() {
    static const char* headers[] = {
"inc/HGC.h",
0
    };
    static const char* includePaths[] = {
"/usr/local/root/build/include",
"/Users/yoyo/Documents/Project/dev/HGC-CMSSW-ANLYSIS/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "DictHGC dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$inc/HGC.h")))  HGC;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "DictHGC dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
#include "inc/HGC.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"HGC", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("DictHGC",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_DictHGC_Impl, {}, classesHeaders, /*has no C++ module*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_DictHGC_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_DictHGC() {
  TriggerDictionaryInitialization_DictHGC_Impl();
}
