#include "Player.h"

void Player::copy(const Player& other)
{
	username = other.username;
	password = other.password;
	level = other.level;
	xp = other.xp;
	max_xp = other.max_xp;
	health = other.health;
	weapon = nullptr;

	if (other.weapon != nullptr) {
		weapon = dynamic_cast<Weapon*>(other.weapon->clone());
	}

	armor = new Armor * [ARMOR_SLOTS] {nullptr};

	for (int i = 0; i < ARMOR_SLOTS; i++) {
		if (other.armor[i] != nullptr) {
			armor[i] = dynamic_cast<Armor*>(other.armor[i]->clone());
		}
	}

	inventory = new Inventory(*other.inventory);
}

void Player::free()
{
	delete weapon;
	for (int i = 0; i < ARMOR_SLOTS; i++)
	{
		delete armor[i];
	}
	delete[] armor;

	delete inventory;
}

Player::Player(MyString::String& username, MyString::String& password, double health)
{
	this->username = username;
	this->password = password;

	this->health = health;

	xp = 0;
	max_xp = LVL_ONE_XP;
	level = 1;

	weapon = nullptr;
	armor = new Armor * [ARMOR_SLOTS] {nullptr};
	inventory = new Inventory();
}

Player::Player(MyString::String& username, MyString::String& password, 
	double health, unsigned int level, unsigned int xp, unsigned int max_xp)
{
	this->username = username;
	this->password = password;

	this->health = health;

	this->xp = xp;
	this->max_xp = max_xp;
	this->level = level;

	weapon = nullptr;
	armor = new Armor * [ARMOR_SLOTS] {nullptr};
	inventory = new Inventory();
}

Player::Player(const Player& other)
{
	copy(other);
}

Player& Player::operator=(const Player& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Player::~Player()
{
	free();
}

const MyString::String& Player::GetName() const
{
	return username;
}

bool Player::IsUser(const MyString::String& name, const MyString::String& pass) const
{
	return (username == name && password == pass);
}

unsigned int Player::GetLevel() const
{
	return level;
}

double Player::GetHealth() const
{
	return health;
}

double Player::GetDefence() const
{
	double defence = 0;
	for (int i = 0; i < ARMOR_SLOTS; i++)
	{
		if (armor[i] != nullptr)
		{
			double dp = armor[i]->use();
			if (dp > 0)
			{
				defence += dp;
			}
		}
	}
	return defence;
}

Inventory* Player::GetInventory()
{
	return inventory;
}

const char* Player::getType(){		
	switch (type)
	{
	case WARRIOR:   return "WARRIOR";
	case ARCHER:   return "ARCHER";
	case MAGE: return "MAGE";
	default:      return "UNKNOWN";
	}
}

bool Player::PickWeapon(const MyString::String& weaponName)
{
	Item* temp = inventory->FindItem(weaponName);
	if (temp == nullptr)
	{
		weapon = nullptr;
		return false;
	}
	weapon = dynamic_cast<Weapon*>(temp);
	if (weapon == nullptr)
	{
		return false;
	}
	return true;
}

bool Player::SetArmorSlot(const MyString::String& armorName, const int slot)
{
	if (slot < 0 || slot >= ARMOR_SLOTS)
	{
		return false;
	}
	
	Item* temp = inventory->FindItem(armorName);
	if (temp == nullptr)
	{
		armor[slot] = nullptr;
		return false;
	}
	armor[slot] = dynamic_cast<Armor*>(temp);
	if (armor[slot] == nullptr)
	{
		return false;
	}
	return true;
}

void Player::droparmor() {
	for (int i = 0; i< ARMOR_SLOTS; i++){
		delete armor[i];
	}
	delete[] armor;
}

void Player::Attack(Player* other)
{
	if (other->GetHealth() + other->GetDefence() <= this->GetPower())
	{
		std::cout << "You defeated " << other->username;
		if (weapon != nullptr)
		{
			std::cout << " using " << weapon->getName();
		}
		else
		{
			std::cout << " using your bare hands";
		}
		std::cout << '\n';
		std::cout << "Rewards:\n";
		std::cout << "Earned " << other->GetLevel() * 2 << " xp\n";
		if (this->AddXP(other->GetLevel() * 2))
		{
			std::cout << "Level up!\n";
		}
		Item* loot = other->inventory->DropRandom();
		if (loot == nullptr)
		{
			std::cout << "Enemy had nothing valuable.\n";
			return;
		}
		std::cout << "You got " << loot->getName() << '\n';
		this->inventory->AddItem(loot);
	}
	else if(this->GetHealth() + this->GetDefence() > other->GetPower())
	{
		std::cout << "You were defeated by " << other->username;
		if (other->weapon != nullptr)
		{
			std::cout << " using " << other->weapon->getName();
		}
		else
		{
			std::cout << " using his bare hands";
		}
		std::cout << '\n';
		other->AddXP(level * 2);
		Item* loot = inventory->DropRandom();
		if (loot != nullptr)
		{
			std::cout <<"You lost " << loot->getName() << '\n';
			other->inventory->AddItem(loot);
		}
	}
	else
	{
		std::cout << "You both survived\n";
	}

	weapon = nullptr;
	other->weapon = nullptr;
	for (int i = 0; i < ARMOR_SLOTS; i++)
	{
		armor[i] = nullptr;
		other->armor[i] = nullptr;
	}
}
