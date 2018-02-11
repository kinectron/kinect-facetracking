# STEP 3: Write bindings to be used when compiling

{
	"targets": [
		{
			"include_dirs": [
				"<!(node -e \"require('nan')\")"
			],
			"target_name": "node_hello",
			"sources": [
				"hello.cc"
			]
		}
	]
}