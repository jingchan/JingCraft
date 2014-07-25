
var _ = require('underscore');
var proto = require('./proto');

var Player = require('./player');
var World = require('./world');

var exports = module.exports = CreateGame;


function CreateGame(){
	var game = {
		player: Player(),
		world: World(),
	}

	_.extend(game, proto);

	game.init();

	return game;
}