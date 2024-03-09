extends CharacterBody2D

const SPEED = 300.0
const GRAVITY = 98.0
var acceleration : float = 0.0

#SPRITES
var facingLeft
@onready var heroSprite = $Sprite2DPlayer
@onready var heroAnimation = $AnimationPlayer

#FSM
@onready var finiteStateMachine = $FiniteStateMachine

#WEAPONS
@onready var rightWeapon = Weapon.new("oneHandSword", "right", $RightWeapon)
@onready var leftWeapon = Weapon.new("oneHandSword", "left", $LeftWeapon)

#LOGIC
func _ready():
	facingLeft = true
	finiteStateMachine.change_state("idle")
	
func _physics_process(delta):
	acceleration += GRAVITY
	
	finiteStateMachine.physics_update(delta)

	velocity.y += acceleration
	acceleration = 0

	heroSprite.flip_h = facingLeft
	
	rightWeapon.update(facingLeft)
	leftWeapon.update(facingLeft)	
	
	move_and_slide()
