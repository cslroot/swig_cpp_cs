//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 4.0.2
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace CS.Foo {

public class Foo : FooBarBase {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;

  public Foo(global::System.IntPtr cPtr, bool cMemoryOwn) : base(cs_fooPINVOKE.Foo_SWIGUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  public static global::System.Runtime.InteropServices.HandleRef getCPtr(Foo obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  protected override void Dispose(bool disposing) {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          cs_fooPINVOKE.delete_Foo(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      base.Dispose(disposing);
    }
  }

  public override string GetName() {
    string ret = cs_fooPINVOKE.Foo_GetName(swigCPtr);
    return ret;
  }

  public Foo Append(int n) {
    Foo ret = new Foo(cs_fooPINVOKE.Foo_Append(swigCPtr, n), false);
    return ret;
  }

  public Foo() : this(cs_fooPINVOKE.new_Foo(), true) {
  }

}

}
