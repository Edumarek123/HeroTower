extends State

func enter():
	entity.heroAnimation.play("jump")
	entity.rightWeapon.animation.play("jump")
	entity.leftWeapon.animation.play("jump")
	
	entity.velocity.y = entity.GRAVITY * -10.0
	
func exit():
	pass
		
func update(delta):
	pass

func physics_update(delta):
	var inputX = Input.get_action_strength("right") - Input.get_action_strength("left")
	if inputX != 0:
		entity.facingLeft = inputX < 0	
		
	entity.velocity.x = inputX * entity.SPEED

func check_triggers():
	if entity.velocity.y > 0 and not entity.is_on_floor():
		change_state("fall")
