/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../headers/Renderer.hpp"

namespace Virtual
{
	Renderer::Renderer(SDL_Window * window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if(!renderer)
			std::cout << "VirtualEye new log: Renderer creation failed!" << std::endl;
	}
	Renderer::~Renderer(void)
	{
		SDL_DestroyRenderer(renderer);
		vector.clear();
	}
	void Renderer::draw(Camera & camera)
	{
		SDL_SetRenderDrawColor(renderer, 125, 0, 255, 255);
		SDL_RenderClear(renderer);
		
		for(auto &i : vector)
			i->draw(renderer, camera);
			
		SDL_RenderPresent(renderer);
	}
	void Renderer::clearScene(void)
	{
		vector.clear();
	}
	void Renderer::loadSprite(std::string path, Vector2<int> position, std::string name, bool is)
	{
		sprite_ptr s(new Sprite);
		
		//Texture & position pushing
        SDL_Texture* texture = IMG_LoadTexture(renderer, path.c_str());
		s->setTexture(texture);
		s->setPosition(position);
		s->setName(name);
		s->setIsStatic(is);
		s->setCropPosition(Vector2<int>(0, 0));
		
		//Detect of Width and Height
		Vector2<int> * par = new Vector2<int>;
		SDL_QueryTexture(&s->getTexture(), NULL, NULL, &par->x, &par->y);
		s->setParametres(*par);
		s->setCropParametres(*par);
		
		delete par;

		vector.push_back(s);
	}
	Vector2<int> Renderer::loadMap(std::string iniPath)
	{
		std::shared_ptr<Map> map(new Map);
		
		int max_num = 0;
		
		//Loading ini file
		std::ifstream file;
		file.open(iniPath);
		if(file.is_open())
		{
			file >> map->width >> map->height >> map->mapPath >> map->texturePath >> map->tilesSize;
			
			//Loading map file
			std::ifstream mapFile;
			mapFile.open(map->mapPath);
			if(mapFile.is_open())
			{
				//Storage info about map
				for(int i = 0; i < map->height; i++)
				{
					std::vector<int> v;
					for(int j = 0; j < map->width; j++)
					{
						//Storage values
						auto buffer = 0;
							
						mapFile >> buffer;
						v.push_back(buffer);
							
						//Identity of max number
						if(buffer > max_num)
							max_num = buffer;
					}
					map->mapString.push_back(v);
				}
				//Closing map file
				mapFile.close();
			}
			else return Vector2<int>(800, 600);
			
			//Closing ini file
			file.close();
		}
		else return Vector2<int>(800, 600);

		SDL_Texture * texture = IMG_LoadTexture(renderer, map->texturePath.c_str());
		
		//Identity of Tiles
		for(int i = 0; i < map->height; i++)
		{
			for(int j = 0; j < map->width; j++)
			{
				sprite_ptr tile(new Sprite);
				tile->setTexture(texture);
					
				//Setting global parametres
				tile->setPosition(Vector2<int>(map->tilesSize * j, map->tilesSize * i));
				tile->setParametres(Vector2<int>(map->tilesSize, map->tilesSize));
					
				//Setting texture parametres
				tile->setCropPosition(Vector2<int>(0, 0));
				tile->setCropParametres(Vector2<int>(map->tilesSize, map->tilesSize));
					
				tile->setName("Map");
				tile->setIsStatic(false);
				
				//Identity of values
				for(int k = 0; k < max_num + 1; k++)
				{
					if(map->mapString[i][j] == k) tile->setCropPosition(Vector2<int>(k * map->tilesSize, 0));
				}
					
				vector.push_back(tile);
			}
		}
		
		//Returning width and height of map
		return Vector2<int>(map->tilesSize * map->width, map->tilesSize * map->height);
	}
	Sprite& Renderer::getElementById(std::string name)
	{
		for(auto &i : vector)
		{
			if(i->getName() == name)
				return *i;
		}
	}
}	
