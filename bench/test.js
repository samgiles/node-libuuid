var Benchmark = require('benchmark');
var libuuid = require('../lib');
var nodeuuid = require('node-uuid');

var suite = new Benchmark.Suite;

suite.add('node-libuuid#generate', function() {
	libuuid.generate();
}).add('node-uuid#v4', function() {
	nodeuuid.v4();
}).on('cycle', function(event) {
	  console.log(String(event.target));
})
.on('complete', function() {
	  console.log('Fastest is ' + this.filter('fastest').pluck('name'));
}).run();
