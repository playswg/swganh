#### NOTICE: THIS FILE IS AUTOGENERATED
#### MODIFICATIONS MAY BE LOST IF DONE IMPROPERLY
#### PLEASE SEE THE ONLINE DOCUMENTATION FOR EXAMPLES

from swgpy.object import *	

def create(kernel):
	result = Creature()

	result.template = "object/creature/player/shared_wookiee_male.iff"
	result.attribute_template_id = -1
	result.stfName("species","wookiee")		
	
	#### BEGIN MODIFICATIONS ####
	####  END MODIFICATIONS  ####
	
	return result