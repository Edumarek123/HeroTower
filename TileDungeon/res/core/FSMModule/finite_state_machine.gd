extends Node

var states = {}
var currentState : String
var currentStateNode
var previousState : String

@export var initialState : String

func _ready():
	var entity = get_parent()
	
	for child in get_children():
		if child is State:
			states[child.name.to_lower()] = child
			child.entity = entity
			child.finiteStateMachine = self		
	#change_state(initialState)
	
func update(delta):
	if not currentStateNode : return
	currentStateNode.update(delta)
	
func physics_update(delta):	
	if not currentStateNode : return
	currentStateNode.physics_update(delta)
	currentStateNode.check_triggers()
	
func change_state(newState):
	if currentStateNode:
		currentStateNode.exit()
	previousState = currentState
	currentState = newState
	currentStateNode = states[currentState]	
	currentStateNode.enter()
