
#include <node.h>
#include <v8.h>

#include <unistd.h>


using namespace v8;


static Handle<Value> OsPipe(const Arguments& args) 
{
    HandleScope scope;
    int pipefd[2];
    
    int ok = pipe(pipefd);

    Local<Array> arr = Array::New();

    arr->Set(0,Number::New(pipefd[0]));
    arr->Set(1,Number::New(pipefd[1]));

    return scope.Close(arr);
}

//=========================


void init(Handle<Object> exports) 
{
  exports->Set(String::NewSymbol("ospipe"),      FunctionTemplate::New(OsPipe)->GetFunction());
}

NODE_MODULE(ospipe, init)
