
#ifndef VISUALS_H
#define VISUALS_H

class Entity;

class Visuals
{
private:
	void PaintPlayer(Entity* ent);

public:
	Visuals(void);

	void PaintTraverse(void);
};

extern Visuals visuals;

#endif
