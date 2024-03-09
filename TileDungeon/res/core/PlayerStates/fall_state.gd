extends State

func enter():
	entity.heroAnimation.play("fall")
	entity.rightWeapon.animation.play("fall")
	entity.leftWeapon.animation.play("fall")
	
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
	if entity.is_on_floor():
		change_state("idle")
	pass
