class_name Weapon extends Node2D

@export var weaponType : String
@export var weaponSide : String

var sprite
var animation 

func _init(_weaponType : String, _weaponSide : String, _path):
	weaponType = _weaponType
	weaponSide = _weaponSide

	sprite = _path.get_children()[0]
	animation = _path.get_children()[1]
	
	sprite.texture = load("res://res/assets/MeleeWeapons/" + weaponType + ".png")	

func update(facingLeft):
	sprite.flip_h = facingLeft
	if weaponSide == "left":
		sprite.offset.x = 18 + (int(facingLeft) * -36)

func play(state : String):
	animation.play(state)
