#include <uuid/uuid.h>
#include <node.h>
#include <v8.h>

using namespace v8;

void Generate(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_string);
    args.GetReturnValue().Set(String::NewFromUtf8(isolate, uuid_string));
}

void GenerateTime(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
	uuid_generate_time(uuid);
	uuid_unparse(uuid, uuid_string);
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, uuid_string));
}

void GenerateRandom(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
	uuid_generate_random(uuid);
	uuid_unparse(uuid, uuid_string);
	args.GetReturnValue().Set(String::NewFromUtf8(isolate, uuid_string));
}

void init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "generate", Generate);
    NODE_SET_METHOD(exports, "generate_time", GenerateTime);
    NODE_SET_METHOD(exports, "generate_random", GenerateRandom);
}

NODE_MODULE(node_libuuid, init)
