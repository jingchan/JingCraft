
var glMatrix = require('gl-matrix');
var vec3 = glMatrix.vec3;

exports.init = function(){
	this.position = vec3.create(0,0,0);
	this.direction = vec3.create(0,1,0);
}

exports.step = function(time){

	this.time = time;
}