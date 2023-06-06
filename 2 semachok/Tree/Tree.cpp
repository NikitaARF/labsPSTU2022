#include <iostream>
#include <functional>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

const float RAD = 35;


class Tree
{
private:

	void add_left(const double& to_add)
	{
		Tree* new_tree = new Tree;
		new_tree->data = to_add;
		new_tree->parent = this;
		left = new_tree;
		++left->size;
	}

	void add_right(const double& to_add)
	{
		Tree* new_tree = new Tree;
		new_tree->data = to_add;
		new_tree->parent = this;
		right = new_tree;
		++right->size;
	}

public:
	Tree* parent;
	Tree* left;
	Tree* right;
	int data;
	int size;

	float x = 500, y = 10;
	int state, level = 1;

	Tree()
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = 0.0;
		size = 0;
	}

	Tree(double data)
	{
		parent = nullptr;
		left = nullptr;
		right = nullptr;
		data = data;
		size = 1;
	}

	Tree(const Tree& another_one)
	{
		parent = another_one.parent;
		left = another_one.left;
		right = another_one.right;
		data = another_one.data;
		size = another_one.size;
	}

	void add(const int& to_add)
	{
		if (size == 0)
			data = to_add;
		else if (left == nullptr)
			add_left(to_add);
		else if (right == nullptr)
			add_right(to_add);
		else if (right->size < left->size)
			right->add(to_add);
		else
			left->add(to_add);

		++size;
	}

	void add_to_search(const int& to_add)
	{
		if (size == 0)
		{
			data = to_add;
			size = 1;
		}
		else
		{
			if (to_add > data)
			{
				++size;
				if (right == nullptr)
				{
					Tree* new_tree = new Tree;
					new_tree->data = to_add;
					new_tree->size = 1;
					right = new_tree;
					new_tree->parent = this;
				}
				else
				{
					right->add_to_search(to_add);
				}
			}
			else if (to_add < data)
			{
				++size;
				if (left == nullptr)
				{
					Tree* new_tree = new Tree;
					new_tree->data = to_add;
					new_tree->size = 1;
					left = new_tree;
					new_tree->parent = this;
				}
				else
				{
					left->add_to_search(to_add);
				}
			}
		}
	}

	void generate()
	{
		cout << "������� ������ ������: ";
		int count;
		cin >> count;

		for (int i = 0; i < count; i++)
		{
			cout << "������� ����� ��� ����������: ";
			int to_add;
			cin >> to_add;
			add(to_add);
		}
	}

	void generate_search()
	{
		cout << "������� ������ ������ ������: ";
		int count;
		cin >> count;

		for (int i = 0; i < count; i++)
		{
			cout << "������� ����� ��� ����������: ";
			double to_add;
			cin >> to_add;
			add_to_search(to_add);
		}
	}

	void for_each(function<void(const int&)> func)
	{
		if (this != nullptr)
		{
			func(data);

			if (left != nullptr)
				left->for_each(func);

			if (right != nullptr)
				right->for_each(func);
		}
	}

	Tree* convert_into_search()
	{
		Tree* new_tree = new Tree;
		for_each([&](const double& data) { new_tree->add_to_search(data); });
		return new_tree;
	}

	Tree* minimum();

	Tree* minimum_search()
	{
		if (left == nullptr)
			return this;
		else
			return left->minimum_search();
	}

	void remove()
	{
		Tree* to_delete = this;
		Tree* dad = parent;

		if (to_delete->left == nullptr and to_delete->right == nullptr)
			del();
		else if (to_delete->left == nullptr and to_delete->right != nullptr)
		{
			to_delete->data = to_delete->right->data;
			to_delete->right->remove();
		}
		else if (to_delete->left != nullptr and to_delete->right == nullptr)
		{
			to_delete->data = to_delete->left->data;
			to_delete->left->remove();
		}
		else
		{
			to_delete->data = to_delete->left->data;
			to_delete->left->remove();
		}
	}

	void remove_search()
	{
		Tree* to_delete = this;
		Tree* dad = parent;

		if (to_delete->left == nullptr and to_delete->right == nullptr)
			del();
		else if (to_delete->left == nullptr and to_delete->right != nullptr)
		{
			to_delete->data = to_delete->right->data;
			to_delete->right->remove_search();
		}
		else if (to_delete->left != nullptr and to_delete->right == nullptr)
		{
			to_delete->data = to_delete->left->data;
			to_delete->left->remove_search();
		}
		else
		{
			Tree* replacer = to_delete->right->minimum_search();
			to_delete->data = replacer->data;

			if (replacer == replacer->parent->left)
			{
				replacer->parent->left = replacer->right;
				if (replacer->right != nullptr)
					replacer->right->parent = replacer->parent;
			}
			else
			{
				replacer->parent->right = replacer->right;
				if (replacer->right != nullptr)
					replacer->right->parent = replacer->parent;
			}

			delete replacer;
		}
	}

	Tree* find(const int& data)
	{
		if (this == nullptr)
			return nullptr;

		if (this->data == data)
			return this;

		if (left->find(data) != nullptr)
			return left->find(data);

		return right->find(data);
	}

	Tree* find_search(const int& data)
	{
		if (this == nullptr)
			return nullptr;

		if (this->data == data)
			return this;

		if (data > this->data)
			return right->find_search(data);

		return left->find_search(data);
	}

	void print_direct()
	{
		if (this)
		{
			cout << data << " ";
			left->print_direct();
			right->print_direct();
		}
	}
	void print_symmetrical()
	{
		if (this)
		{
			left->print_symmetrical();
			cout << data << " ";
			right->print_symmetrical();
		}
	}

	void print_reverse()
	{
		if (this)
		{
			left->print_reverse();
			right->print_reverse();
			cout << data << " ";
		}
	}

	friend ostream& operator<<(ostream& stream, const Tree* start)
	{
		if (start != nullptr)
		{
			stream << start->data;
		}
		return stream;
	}

	void del()
	{
		if (this != nullptr)
		{
			if (left != nullptr)
				left->del();

			if (right != nullptr)
				right->del();

			parent->size -= size;

			if (this == parent->left)
				parent->left = nullptr;
			else
				parent->right = nullptr;

			delete this;
		}
	}
};

Tree* min_of_three(Tree* mas[3])
{
	Tree* min = new Tree;
	min = mas[0];

	if (mas[1]->data < min->data)
		min = mas[1];
	if (mas[2]->data < min->data)
		min = mas[2];

	return min;
}

Tree* Tree::minimum()
{
	Tree* mas[3];
	mas[0] = this;

	if (left != nullptr)
		mas[1] = left->minimum();
	else
		mas[1] = this;

	if (right != nullptr)
		mas[2] = right->minimum();
	else
		mas[2] = this;

	return min_of_three(mas);
}

int depth;

void count_levels(Tree* root)
{
	if (root != nullptr)
	{
		if (root->parent != nullptr)
			root->level = root->parent->level + 1;

		if (depth < root->level)
			depth = root->level;

		count_levels(root->left);
		count_levels(root->right);
	}
}

void calculate_coords(Tree* node)
{
	if (node != nullptr)
	{
		if (node->parent != nullptr)
		{
			if (node->level == 2)
				node->x = node->x + node->state * (pow(2, depth - 1) / 2) * 40;
			else
				node->x = node->parent->x + node->state * (pow(2, depth - 1) / pow(2, node->level - 1)) * 40;
			node->y = node->parent->y + 80;
		}

		if (node->left != nullptr)
		{
			node->left->state = -1;
			calculate_coords(node->left);
		}

		if (node->right != nullptr)
		{
			node->right->state = 1;
			calculate_coords(node->right);
		}
	}
}

void draw_lines(Tree* node, RenderWindow& window)
{
	if (node != nullptr)
	{
		if (node->parent != nullptr)
		{
			vector<Vertex> line =
			{
				Vertex(Vector2f(node->parent->x + RAD, node->parent->y + RAD), Color::Black),
				Vertex(Vector2f(node->x + RAD, node->y + RAD), Color::Black)
			};
			window.draw(&line[0], line.size(), Lines);
		}

		if (node->left != nullptr)
			draw_lines(node->left, window);

		if (node->right != nullptr)
			draw_lines(node->right, window);
	}
}

void draw_nodes(Tree* node, RenderWindow& window)
{
	if (node != nullptr)
	{
		CircleShape circle(RAD);
		circle.setPosition(node->x, node->y);
		circle.setFillColor(Color::White);
		circle.setOutlineColor(Color::Black);
		circle.setOutlineThickness(3);

		Font font;
		font.loadFromFile("ofont.ru_CampusOtl.ttf");

		stringstream txt;
		txt << node->data;
		Text text(txt.str(), font, 35);
		text.setPosition(node->x + RAD / 2, node->y + RAD / 2);
		text.setFillColor(Color::Black);

		window.draw(circle);
		window.draw(text);

		if (node->left != nullptr)
			draw_nodes(node->left, window);

		if (node->right != nullptr)
			draw_nodes(node->right, window);
	}
}

void draw(Tree* tree)
{
	RenderWindow MainWindow(VideoMode(1200, 500), "Our tree");

	depth = 0;

	count_levels(tree);
	calculate_coords(tree);

	while (MainWindow.isOpen())
	{
		Event event;

		while (MainWindow.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MainWindow.close();
				break;
			}
		}

		MainWindow.clear(Color::White);
		draw_lines(tree, MainWindow);
		draw_nodes(tree, MainWindow);
		MainWindow.display();
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	Tree* bush = new Tree;

	bush->generate();
	cout << "������ �����: ";
	bush->print_direct();
	cout << "\n������������ �����: ";
	bush->print_symmetrical();
	cout << "\n�������� �����: ";
	bush->print_reverse();
	cout << "\n������: " << endl;
	draw(bush);
	

	bush->minimum()->remove();
	cout << "����� �������� �������� � ������� ������: " << endl;
	draw(bush);

	Tree* search_bush = bush->convert_into_search();
	cout << "����������� � �������� ������ ������: " << endl;
	draw(search_bush);

	search_bush->minimum_search()->remove_search();
	cout << "����� �������� �������� � �������� ������: " << endl;
	draw(search_bush);

	return 0;
}
