#include "Mesh.h"
#include "draw_mushroom.h"
#include <string>

 draw_mushroom::draw_mushroom(glm::vec3 p, glm::vec3 s, glm::vec3 r, int up)
				: draw_object(p, s, r) {
  
  //set the parameters of body
  meshes.push_back(Mesh(mPoint(position.x, position.y, position.z),
						mPoint(scale.x, scale.y, scale.z),
						mPoint(rot.x, rot.y, rot.z),
						Material(mPoint(1,1,0), mPoint(1,1,1), mPoint(1,0,1))));

  //this should be polka dot texture, but isnt working
  meshes.push_back(Mesh(mPoint(position.x, position.y, position.z),
						mPoint(scale.x, scale.y, scale.z),
						mPoint(rot.x, rot.y, rot.z),
						Material(mPoint(1-up,up,0), mPoint(1,1,1), mPoint(1,0,0))));

  //set parameters of eyes
  meshes.push_back(Mesh(mPoint(position.x, position.y, position.z),
						mPoint(scale.x, scale.y, scale.z),
						mPoint(rot.x, rot.y, rot.z),
						Material())); 

  //set spots
  meshes.push_back(Mesh(mPoint(position.x, position.y, position.z),
			mPoint(scale.x, scale.y, scale.z),
			mPoint(rot.x, rot.y, rot.z),
			Material(mPoint(1, 1, 1), mPoint(1, 1, 1), mPoint(1, 1, 1)))); 
  
  hitboxes.push_back(new Cube(position.x, position.y+2*scale.y, position.z+scale.z, "brickblock", 2*scale.x));

  type = "mushroom";
  is1up = up;

  load();
}

void draw_mushroom::setHitboxes() {
	hitboxes[0]->move(position.x, position.y+2*scale.y, position.z+scale.z);
	for(int n = 0; n < hitboxes.size(); n++) {
		hitboxes[n]->velocity = velocity;
	}
}

//load all three
void draw_mushroom::load() {
  meshes[0].loadOBJ("objLoader/mushroom_body.obj");
  meshes[1].loadOBJ("objLoader/mushroom_top.obj");
  meshes[2].loadOBJ("objLoader/mushroom_eyes.obj");
  meshes[3].loadOBJ("objLoader/mushroomspots.obj");
}
