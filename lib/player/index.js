
var _ = require('underscore');
var proto = require('./proto');

var exports = module.exports = CreatePlayer;


function CreatePlayer(){
	var player = {

	}

	_.extend(player, proto);

	player.init();
	
	return player;
}