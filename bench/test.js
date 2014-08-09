var Benchmark = require('benchmark');
var libuuid = require('../lib');
var nodeuuid = require('node-uuid');

var suitev4 = new Benchmark.Suite;

suitev4.add('node-libuuid#generate_random', function() {
	libuuid.v4();
}).add('node-uuid#v4', function() {
	nodeuuid.v4();
}).on('cycle', function(event) {
	  console.log(String(event.target));
})
.on('complete', function() {
	  console.log('Fastest is ' + this.filter('fastest').pluck('name'));
}).run();

var suitev1 = new Benchmark.Suite;

suitev1.add('node-libuuid#v1', function() {
	libuuid.v1();
}).add('node-uuid#v1', function() {
	nodeuuid.v1();
}).on('cycle', function(event) {
	  console.log(String(event.target));
})
.on('complete', function() {
	  console.log('Fastest is ' + this.filter('fastest').pluck('name'));
}).run();
