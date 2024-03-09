extends Node

class_name State

var entity
var finiteStateMachine

func enter():
	pass
	
func exit():
	pass
		
func update(delta):
	pass

func physics_update(delta):
	pass

func change_state(newState):
	finiteStateMachine.change_state(newState)

func check_triggers():
	pass
