#include <uuid/uuid.h>
#include <node.h>
#include <v8.h>

using namespace v8;

Handle<Value> Generate(const Arguments& args) {
    HandleScope scope;
    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
    uuid_generate(uuid);
    uuid_unparse(uuid, uuid_string);
    return scope.Close(String::New(uuid_string));
}

Handle<Value> GenerateTime(const Arguments& args) {
	HandleScope scope;
    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
	uuid_generate_time(uuid);
	uuid_unparse(uuid, uuid_string);
	return scope.Close(String::New(uuid_string));
}

Handle<Value> GenerateRandom(const Arguments& args) {
	HandleScope scope;
    unsigned char uuid[53];
	char* uuid_string = (char*)(uuid + 16);
	uuid_generate_random(uuid);
	uuid_unparse(uuid, uuid_string);
	return scope.Close(String::New(uuid_string));
}

void init(Handle<Object> exports) {
    exports->Set(String::NewSymbol("generate"), FunctionTemplate::New(Generate)->GetFunction());
	exports->Set(String::NewSymbol("generate_time"), FunctionTemplate::New(Generate)->GetFunction());
	exports->Set(String::NewSymbol("generate_random"), FunctionTemplate::New(GenerateRandom)->GetFunction());
}

NODE_MODULE(node_libuuid, init)
