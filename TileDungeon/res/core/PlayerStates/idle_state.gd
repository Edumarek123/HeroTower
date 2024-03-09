extends State

func enter():
	entity.heroAnimation.play("idle")
	entity.rightWeapon.play("idle")
	entity.leftWeapon.play("idle")
	pass
	
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
	if entity.velocity.x != 0:
		change_state("run")		

	if Input.is_action_pressed("up"):
		change_state("jump")
	
	if entity.velocity.y > 0 and not entity.is_on_floor():
		change_state("fall")
