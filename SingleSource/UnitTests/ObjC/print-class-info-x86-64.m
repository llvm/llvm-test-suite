#include <Foundation/NSObject.h>
#include <objc/runtime.h>
#include <stdio.h>
#include <stdlib.h>

@protocol UnusedProtocol
+(void) makeWaffles;
@end

@protocol P2
@end

@protocol P <P2>
@required
+(void) requiredProtocolClassMethod;
-(void) requiredProtocolInstanceMethod;
@optional
+(void) optionalProtocolClassMethod;
-(void) optionalProtocolInstanceMethod;

@required
@property int requiredProtocolProperty;
@optional
@property int optionalProtocolProperty; // XXX this is not actually
                                        // optional in Obj-C 2? or
                                        // maybe just in old ABI?
@end

@protocol CategoryProtocol
+(void) categoryClassMethod;
-(void) categoryInstanceMethod;
@end

@interface A : NSObject <P>  {
@private
  int privateVar;
@protected
  int protectedVar;
@public
  int publicVar;
  __weak id weakVar;
  __strong id strongVar;
  
  int halfDynamicA, halfDynamicB;
}

@property(assign) int requiredProtocolProperty;
@property(assign) int optionalProtocolProperty;

@property(assign) int Ptest_a;
@property(copy) id Ptest_b;
@property(retain) id Ptest_c;

@property(getter=iGetThings) int things;
@property(setter=iSetOtherThings:) int otherThings;

@property(assign) int dynamicNotReally;
@property(assign) int halfDynamicA;
@property(assign) int halfDynamicB;

+(void) classMethod;
-(void) instanceMethod;
@end

@interface A ()
+(void) extendedClassMethod;
-(void) extendedInstanceMethod;
+(void) requiredProtocolClassMethod;
-(void) requiredProtocolInstanceMethod;
@end

@implementation A
@dynamic Ptest_a, Ptest_b, Ptest_c;
@dynamic things, otherThings;

@dynamic dynamicNotReally;
-(int) dynamicNotReally {};
-(void) dynamicNotReally: (int) arg {};

@synthesize halfDynamicA;
-(int) halfDynamicA {};

@synthesize halfDynamicB;
-(void) halfDynamicB: (int) arg {};

@synthesize requiredProtocolProperty = privateVar;
#ifdef ABI2
@synthesize optionalProtocolProperty = someRandomVar;
#else
@synthesize optionalProtocolProperty = publicVar;
#endif

+(void) classMethod {
  printf("I am a class method\n");
}
-(void) instanceMethod {
  printf("I am an instance method\n");
}

+(void) requiredProtocolClassMethod {
  printf("I am a required protocol class method\n");
}

-(void) requiredProtocolInstanceMethod {
  printf("I am a required protocol instance method\n");
}

+(void) extendedClassMethod {
  printf("I am an extended class method\n");
}
-(void) extendedInstanceMethod {
  printf("I am an extended instance method\n");
}
@end

@interface A ( A_Category ) <CategoryProtocol>
+(void) categoryClassMethod;
-(void) categoryInstanceMethod;

@property(assign) int categoryProperty;
@end

@implementation A ( A_Category )
@dynamic categoryProperty;

+(void) categoryClassMethod {
}
-(void) categoryInstanceMethod {
}
@end

/***/

int ivar_cmp(const void *av, const void *bv) {
  const Ivar *a = av;
  const Ivar *b = bv;
  return strcmp(ivar_getName(*a), ivar_getName(*b));
}

int methodDescription_cmp(const void *av, const void *bv) {
  const struct objc_method_description *a = av;
  const struct objc_method_description *b = bv;
  return strcmp(sel_getName(a->name), sel_getName(b->name));
}

int method_cmp(const void *av, const void *bv) {
  const Method *a = av;
  const Method *b = bv;
  return strcmp(method_getName(*a), method_getName(*b));
}

int property_cmp(const void *av, const void *bv) {
  const objc_property_t *a = av;
  const objc_property_t *b = bv;
  return strcmp(property_getName(*a), property_getName(*b));
}

int protocol_cmp(const void *av, const void *bv) {
  Protocol * const *a = av;
  Protocol * const *b = bv;
  return strcmp(protocol_getName(*a), protocol_getName(*b));
}

void sort_ivars(Ivar *ivars, unsigned numIvars) {
  qsort(ivars, numIvars, sizeof(*ivars), ivar_cmp);
}

void sort_methodDescriptions(struct objc_method_description *methods, unsigned numMethods) {
  qsort(methods, numMethods, sizeof(*methods), methodDescription_cmp);
}

void sort_methods(Method *methods, unsigned numMethods) {
  unsigned i;
  qsort(methods, numMethods, sizeof(*methods), method_cmp);
}

void sort_properties(objc_property_t *properties, unsigned numProperties) {
  qsort(properties, numProperties, sizeof(*properties), property_cmp);
}

void sort_protocols(Protocol **protocols, unsigned numProtocols) {
  qsort(protocols, numProtocols, sizeof(*protocols), protocol_cmp);
}

/***/

static int indent = 0;
#define PRINT1(e0,t0) printf("%*s" #e0 ": %" #t0 "\n", indent*2, "", e0)
#define PRINT2(e0,t0,e1,t1) printf("%*s" #e0 ": %" #t0 ", " #e1 ": %" #t1 "\n", indent*2, "", e0, e1)
#define PRINT3(e0,t0,e1,t1,e2,t2) printf("%*s" #e0 ": %" #t0 ", " #e1 ": %" #t1 ", " #e2 ": %" #t2 "\n", indent*2, "", e0, e1, e2)
#define PRINT4(e0,t0,e1,t1,e2,t2,e3,t3) printf("%*s" #e0 ": %" #t0 ", " #e1 ": %" #t1 ", " #e2 ": %" #t2 ", " #e3 ": %" #t3 "\n", indent*2, "", e0, e1, e2, e3)
#define PRINT5(e0,t0,e1,t1,e2,t2,e3,t3,e4,t4) printf("%*s" #e0 ": %" #t0 ", " #e1 ": %" #t1 ", " #e2 ": %" #t2 ", " #e3 ": %" #t3 ", " #e4 ": %" #t4 "\n", indent*2, "", e0, e1, e2, e3, e4)
void printInfo(Class c, int printData) {
  unsigned i;

  ++indent;
  PRINT1(c != 0, d);
  PRINT1(class_getName(c), s);
  PRINT1(object_getClassName(c), s);
  PRINT1(objc_getClass(class_getName(c)) == c, d);
  PRINT1(class_conformsToProtocol(c, @protocol(P)), d);
  
  unsigned numIvars;
  Ivar *ivars = class_copyIvarList(c, &numIvars);
  sort_ivars(ivars, numIvars);
  PRINT1(numIvars, d);
  if (printData) {
    ++indent;
    for (i=0; i<numIvars; ++i) {
      Ivar ivar = ivars[i];
      PRINT2(i, d, ivar_getName(ivar), s);
      PRINT2(i, d, ivar_getOffset(ivar), d);
      PRINT2(i, d, ivar_getTypeEncoding(ivar), s);
      PRINT2(i, d, class_getInstanceVariable(c, ivar_getName(ivar)) == ivar, d);
    }
    --indent;
  }

  unsigned numMethods;
  Method *methods = class_copyMethodList(c, &numMethods);
  sort_methods(methods, numMethods);
  PRINT1(numMethods, d);
  if (printData) {
    ++indent;
    for (i=0; i<numMethods; ++i) {
      Method method = methods[i];
      unsigned j, numArgs;
      PRINT2(i, d, sel_getName(method_getName(method)), s);
      PRINT2(i, d, class_respondsToSelector(c, method_getName(method)), d);
      PRINT2(i, d, !strcmp(method_getName(method),sel_getName(method_getName(method))), d);
      PRINT2(i, d, method_getName(method) == sel_getUid((char*) method_getName(method)), d);
      PRINT2(i, d, class_getClassMethod(c, sel_getUid((char*) method_getName(method))) == method, d);
      PRINT2(i, d, class_getInstanceMethod(c, sel_getUid((char*) method_getName(method))) == method, d);
      PRINT2(i, d, numArgs = method_getNumberOfArguments(method), d);    
      PRINT2(i, d, method_copyReturnType(method), s);
      for (j=0; j<numArgs; ++j) {
        PRINT3(i, d, j, d, method_copyArgumentType(method, j), s);
      }      
      PRINT2(i, d, method_getTypeEncoding(method), s);
    }
    --indent;
  }

  unsigned numProperties;
  objc_property_t *properties = class_copyPropertyList(c, &numProperties);
  sort_properties(properties, numProperties);
  PRINT1(numProperties, d);
  if (printData) {
    ++indent;
    for (i=0; i<numProperties; ++i) {
      objc_property_t property = properties[i];
      PRINT2(i, d, property_getName(property), s);
      PRINT2(i, d, property_getAttributes(property), s);
      PRINT2(i, d, class_getProperty(c, property_getName(property)) == property, d);
    }
    --indent;
  }

  unsigned numProtocols;
  Protocol **protocols = class_copyProtocolList(c, &numProtocols);
  sort_protocols(protocols, numProtocols);
  PRINT1(numProtocols, d);
  if (printData) {
    ++indent;
    for (i=0; i<numProtocols; ++i) {
      Protocol *protocol = protocols[i];
      unsigned j;

      PRINT2(i, d, protocol_getName(protocol), s);
      PRINT2(i, d, objc_getProtocol(protocol_getName(protocol))==protocol, d); 

      unsigned isRequired;
      unsigned isInstance;
      for (isRequired = 0; isRequired < 2; ++isRequired) {
        for (isInstance = 0; isInstance < 2; ++isInstance) {
          unsigned numProtocolMethods;
          struct objc_method_description *methods = protocol_copyMethodDescriptionList(protocol, 
                                                                                       isRequired,
                                                                                       isInstance,
                                                                                       &numProtocolMethods);
          sort_methodDescriptions(methods, numProtocolMethods);
          PRINT4(i, d, isRequired, d, isInstance, d, numProtocolMethods, d);
          for (j=0; j<numProtocolMethods; ++j) {
            PRINT3(i, d, j, d, sel_getName(methods[j].name), s);
            PRINT3(i, d, j, d, methods[j].types, s);
          }
        }
      }
      unsigned numProperties;
      objc_property_t *properties = protocol_copyPropertyList(protocol, &numProperties);
      sort_properties(properties, numProperties);
      PRINT2(i, d, numProperties, d);
      ++indent;
      for (j=0; j<numProperties; ++j) {
        objc_property_t property = properties[j];
        PRINT3(i, d, j, d, property_getName(property), s);
        PRINT3(i, d, j, d, property_getAttributes(property), s);
        for (isRequired = 0; isRequired < 2; ++isRequired)
          for (isInstance = 0; isInstance < 2; ++isInstance)
            PRINT5(i, d, j, d, isRequired, d, isInstance, d, protocol_getProperty(protocol, property_getName(property), isRequired, isInstance) == property, d);
      }
      --indent;

      unsigned numSubProtocols;
      Protocol **subProtocols = protocol_copyProtocolList(protocol, &numSubProtocols);
      sort_protocols(subProtocols, numSubProtocols);
      PRINT2(i, d, numSubProtocols, d);
      ++indent;
      for (j=0; j<numSubProtocols; ++j) {
        Protocol *subProtocol = subProtocols[j];
        PRINT3(i, d, j, d, protocol_getName(protocol), s);
      } 
      --indent;      
    }
    --indent;
  }
 
  PRINT1((int) class_getInstanceSize(c), d);

  PRINT1(class_getIvarLayout(c), s);

  PRINT1(class_getSuperclass(c) != 0, d);

  Class s = class_getSuperclass(c);
  if (s) {
    printInfo(s, 0);
  }

  PRINT1(class_getVersion(c), d);

  PRINT1(class_getWeakIvarLayout(c), s);

  --indent;
}

// class_getClassVariable
// class_getMethodImplementation
// class_getMethodImplementation_stret
// class_setIvarLayout
// class_setSuperclass
// class_setVersion
// class_setWeakIvarLayout

// method_exchangeImplementations
// method_getArgumentType
// method_getReturnType
// method_getTypeEncoding
// method_setImplementation

// objc_allocateClassPair
// objc_copyProtocolList
// objc_duplicateClass
// objc_getFutureClass
// objc_lookupClass
// objc_msgSend
// objc_msgSendSuper
// objc_msgSendSuper_stret
// objc_msgSend_fpret
// objc_msgSend_stret
// objc_registerClassPair
// objc_setFutureClass

// object_copy
// object_dispose
// object_getIndexedIvars
// object_getInstanceVariable
// object_getIvar
// object_setClass
// object_setInstanceVariable
// object_setIvar

// protocol_conformsToProtocol
// protocol_getMethodDescription
// protocol_getProperty
// protocol_isEqual

// sel_isEqual
// sel_registerName

// class_addMethod
// class_addProtocol
// class_createInstance

unsigned Verbose = 0;

int main() {
  unsigned i;

  printf("-- A class --\n");
  printInfo([ A class], 1);
  printf("-- A metaclass --\n");
  PRINT1(object_getClass([A class]) == objc_getMetaClass("A"), d);
  printInfo(objc_getMetaClass("A"), 1);

  unsigned numObjCProtocols;
  Protocol **protocols = objc_copyProtocolList(&numObjCProtocols);
  PRINT1(numObjCProtocols, d);
  if (Verbose) {
    ++indent;
    for (i=0; i<numObjCProtocols; ++i) {
      Protocol *protocol = protocols[i];
      PRINT2(i, d, protocol_getName(protocol), s);
    }
    --indent;
  }

  unsigned numClasses = objc_getClassList(0, 0);
  Class *classes = calloc(numClasses, sizeof(*classes));
  objc_getClassList(classes, numClasses * sizeof(*classes));
  PRINT1(numClasses, d);
  if (Verbose) {
    for (i=0; i<numClasses; ++i) {
      PRINT2(i, d, class_getName(classes[i]), s);
    }
  }

  return 0;
}

// rc && echo "--gcc--" && gcc -fnext-runtime print-class-info.m -lobjc -framework Foundation && ./a.out && echo "--ccc--" && ccc -fnext-runtime print-class-info.m -lobjc -framework Foundation && ./a.out
// rc && echo "--gcc--" && gcc -fnext-runtime print-class-info.m -lobjc -framework Foundation && ./a.out && echo "--ccc--" && ccc -fnext-runtime print-class-info.m -lobjc -framework Foundation && ./a.out && ../TestRunner.sh print-class-info.m
// rc && ../TestRunner.sh print-class-info.m
