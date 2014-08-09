# Node libuuid

Simple `node` binding to the native libuuid implementation.

## Install

`npm install node-libuuid`

# API

### libuuid.v1()

Generate and return a time based UUID.

Returns the `string` form of the UUID.

### libuuid.v4()

Generate and return a secure random UUID (see `uuid_generate_random(3)`)

Returns the `string` form of the UUID.

# Benchmarks

Run `npm run-script bench`

Currently it compares just against `node-uuid`.

```
node-libuuid#generate_random x 5,501,355 ops/sec ±1.32% (100 runs sampled)
node-uuid#v4 x 201,565 ops/sec ±2.84% (84 runs sampled)
Fastest is node-libuuid#generate_random

node-libuuid#v1 x 5,434,475 ops/sec ±1.85% (97 runs sampled)
node-uuid#v1 x 1,028,694 ops/sec ±1.91% (94 runs sampled)
Fastest is node-libuuid#v1
```

# Reporting Errors

Please include operating system and version and libuuid install status.

#### License Info

Samuel Giles, GPLv2.
