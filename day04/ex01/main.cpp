#include "Character.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main2()
{
	Character* me = new Character("me");
	std::cout << *me;

	std::cout << "-- crating weapon --" << std::endl;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	AWeapon* bl;
	bl = pf;

	std::cout << "-- testing equip / attack --" << std::endl;
	me->equip(bl);
	me->attack(b);
	std::cout << *me;

	me->equip(pr);
	std::cout << *me;

	me->equip(pf);
	me->attack(b);
	std::cout << *me;

	me->equip(pr);
	std::cout << *me;

	me->attack(b);
	if (b)
        std::cout << b->getType() << " has " << b->getHP() << " HP." << std::endl;
	std::cout << *me;

	std::cout << "-- testing ap --" << std::endl;
	me->attack(c);
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	me->attack(c);
	me->attack(c);
	std::cout << *me;
	me->attack(c);
	me->attack(c);
	me->attack(c);
	std::cout << *me;

	std::cout << "-- recovery ap --" << std::endl;
	std::cout << *me;
	me->recoverAP();
	std::cout << *me;
	me->attack(c);

	std::cout << "-- recovery ap max --" << std::endl;
	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;
	me->recoverAP();
	me->recoverAP();
	std::cout << *me;

	std::cout << "-- testing ennemy resistance --" << std::endl;
	std::cout << *me;
	std::cout << pr->getDamage() << std::endl;
	if (b)
        std::cout << b->getType() << " has " << b->getHP() << " HP. (before)" << std::endl;
	me->attack(b);
	if (b)
        std::cout << b->getType() << " has " << b->getHP() << " HP. (after)" << std::endl;
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. (before)" << std::endl;
	me->attack(c);
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. (after)" << std::endl;

	std::cout << "-- killing ennemy --" << std::endl;
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. 1" << std::endl;
	me->recoverAP();
	me->recoverAP();
	me->attack(c);
	me->attack(c);
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. 2" << std::endl;
	me->recoverAP();
	me->recoverAP();
	me->attack(c);
	me->attack(c);
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. 3" << std::endl;
	me->recoverAP();
	me->recoverAP();
	me->attack(c);
	me->attack(c);
	if (c)
        std::cout << c->getType() << " has " << c->getHP() << " HP. 4" << std::endl;
	std::cout << *me;

	delete pf;
	delete pr;
	delete me;
	return 0;
}

int main()
{
	main2();
	while (1)
	{ }
	return 1;
}