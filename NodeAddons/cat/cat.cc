#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Method(const Arguments& args) {
  HandleScope scope;
  return scope.Close(String::New("Meowwwwwww.... !"));
}


// Here, we take the target, which is presumably the Node.js binding, and set a property on it.
// We are using V8 to templatize and instantiate a new function that we’ve called “Method”

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("speak"),
      FunctionTemplate::New(Method)->GetFunction());
}



// Here we declare the NODE_MODULE.  
// It’s called “nodecat”, and it’s entry point is “init”.

NODE_MODULE(nodecat, init)