
var _ = require('underscore');
var proto = require('./proto');

var exports = module.exports = CreateWorld;


function CreateWorld(){
	var world = {

	}

	_.extend(world, proto);

	world.init();
	
	return world;
}