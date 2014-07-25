/**
 * # JingCraft - Index
 *
 * Entry point for JingCraft
 *
 * Pixedy
 *
 * Copyright (c) 2014 Jing Chan <jingchan@gmail.com>
 *
 * Private Use Only - Unauthorized use prohibited
 *
 * -----------------------------------------------------------------------------
 */

var WebGL = require('node-webgl');
var Game = require('./lib');

// Make sure correct environment
var nodejs = (typeof window === 'undefined');
if(!nodejs) {
  throw Error("node_app.js should be run in node, not the browser.")
}

document = WebGL.document();
alert=console.log;

document.setTitle("Pixedy");

var canvas = document.createElement("canvas", 800, 600);

var glSettings = {
  alpha: true,
  depth: false,
  stencil: false,
  antialias: false,
  premultipliedAlpha: false,
  preserveDrawingBuffer: true
};

// Get WebGL Context and construct Pixedy object
var context = canvas.getContext('webgl', glSettings) || canvas.getContext('experimental-webgl', glSettings);

var game = Game();

var step = function(time){ 
  //game loop
  game.step(time);
  document.requestAnimationFrame(step,1000/60);
}
document.requestAnimationFrame(step,1000/60);

// module.exports = client;