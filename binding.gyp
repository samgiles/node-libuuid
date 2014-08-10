{
	"targets": [
		{
			"target_name": "node_libuuid",
			"sources": [ "lib/libuuid.cc" ],
            "cflags": ['-g', '-O3'],
            "conditions": [
                ['OS=="linux"', {
                    'libraries': [ '-luuid' ]
                }]
            ]
		}
	]
}
