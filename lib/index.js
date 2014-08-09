var node_libuuid = require('../build/Release/node_libuuid');

node_libuuid.v1 = node_libuuid.generate_time;
node_libuuid.v4 = node_libuuid.generate_random;

module.exports = node_libuuid;
