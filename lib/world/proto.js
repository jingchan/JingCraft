
var glMatrix = require('gl-matrix');
var vec3 = glMatrix.vec3;

exports.init = function(){
	this.tris = [
		[[-10,-10,-1], [-10,10,-1], [10,-10,-1]],
		[[-10,10,-1], [10,-10,-1], [10,10,-1]],
	]
}

exports.step = function(time){

}