
var _ = require('underscore');
var proto = require('./proto');

var exports = module.exports = CreateRenderer;


function CreateRenderer(){
	var render = {

	}

	_.extend(render, proto);

	render.init();
	
	return render;
}