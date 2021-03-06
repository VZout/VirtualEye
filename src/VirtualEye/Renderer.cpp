/*  =============================================================*
 *   VirtualEye (c)         Dmitro Szewczuk                      *
 *   MIT License  http://choosealicense.com/licenses/mit         *
 *  =============================================================*/ 

#include "../../include/VirtualEye/Renderer.hpp"

namespace Virtual
{
	Renderer::Renderer(SDL_Window * window)
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if(!renderer)
			DebugLog::getInstance().addToLog("VirtualEye new log: Renderer creation failed!");

		map = std::shared_ptr<Map>(new Map);
		camera = std::shared_ptr<Camera>(new Camera);
	}
	Renderer::~Renderer(void)
	{
		SDL_DestroyRenderer(renderer);
		spriteVector.clear();
		labelVector.clear();
	}
	void Renderer::draw(Camera & camera)
	{
		SDL_SetRenderDrawColor(renderer, 125, 0, 255, 255);
		SDL_RenderClear(renderer);
		
		//Rendering map
		for(int i = 0; i < map->tiles.size(); i++)
			for(auto &o : map->tiles[i])
				o->draw(renderer, camera);
			
		//Rendering sprites
		for(auto &i : spriteVector)
			i->draw(renderer, camera);
			
		//Rendering labels
		for(auto &i : labelVector)
			i->draw(renderer, camera);
			
		SDL_RenderPresent(renderer);
	}
	void Renderer::clearScene(void)
	{
		spriteVector.clear();
	}
	void Renderer::loadSprite(std::string path, Vector2<int> position, std::string name, bool is)
	{
		sprite_ptr s(new Sprite);
		
		//Texture & position pushing
		s->setTexture(IMG_LoadTexture(renderer, path.c_str()));
		
		if(s->getTexture() == NULL)
			DebugLog::getInstance().addToLog("VirtualEye new log: sprite loading form " + path + " failed!");
			
		s->setPosition(position);
		s->setName(name);
		s->setIsStatic(is);
		s->setCropPosition(Vector2<int>(0, 0));
		s->setIsDrawing(true);
		s->setAngle(0);
		s->setFlip(FLIP(NONE));
		
		//Detect of Width and Height
		Vector2<int> * par = new Vector2<int>;
		SDL_QueryTexture(s->getTexture(), NULL, NULL, &par->x, &par->y);
		s->setParametres(*par);
		s->setCropParametres(*par);
		
		delete par;

		spriteVector.push_back(s);
	}
	void Renderer::loadLabel(std::string fontpath, std::string text, Vector2<int> position, std::string name, Color color, int size, bool is)
	{
		std::shared_ptr<Label> label(new Label);
		
		//Texture & position pushing
		std::shared_ptr<Font> font(new Font);
		
		font->setFont(TTF_OpenFont(fontpath.c_str(), size));
		label->setTexture(SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Blended(font->getFont(), text.c_str(), {color.r, color.g, color.b})));
		
		label->setPosition(position);
		label->setName(name);
		label->setIsStatic(is);
		label->setCropPosition(Vector2<int>(0, 0));
		label->setIsDrawing(true);
		label->setAngle(0);
		label->setFlip(FLIP(NONE));
		label->setColor(color);
		label->setFont(font);
		
		//Detect of Width and Height
		Vector2<int> * par = new Vector2<int>;
		SDL_QueryTexture(label->getTexture(), NULL, NULL, &par->x, &par->y);
		label->setParametres(*par);
		label->setCropParametres(*par);
		
		delete par;

		labelVector.push_back(label);
	}
	Vector2<int> Renderer::loadMap(std::string iniPath)
	{
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
					map->numbers.push_back(v);
				}
				//Closing map file
				mapFile.close();
			}
			else 
			{
				DebugLog::getInstance().addToLog("VirtualEye new log: map file " + map->mapPath + " load failed!");
				return Vector2<int>(800, 600);
			}
			//Closing ini file
			file.close();
		}
		else 
		{
			DebugLog::getInstance().addToLog("VirtualEye new log: map file " + iniPath + " load failed!");
			return Vector2<int>(800, 600);
		}
		
		map->texture.setTexture(IMG_LoadTexture(renderer, map->texturePath.c_str()));
		
		if(map->texture.getTexture() == NULL)
			DebugLog::getInstance().addToLog("VirtualEye new log: map tiles loading form " + map->texturePath + " failed!");

		//Identity of Tiles
		for(int i = 0; i < map->height; i++)
		{
			std::vector<std::shared_ptr<Tile>> v;
			for(int j = 0; j < map->width; j++)
			{
				std::shared_ptr<Tile> tile(new Tile);
				tile->setTexture(map->texture.getTexture());
					
				//Setting global parametres
				tile->setPosition(Vector2<int>(map->tilesSize * j, map->tilesSize * i));
				tile->setParametres(Vector2<int>(map->tilesSize, map->tilesSize));
					
				//Setting texture parametres
				tile->setCropPosition(Vector2<int>(0, 0));
				tile->setCropParametres(Vector2<int>(map->tilesSize, map->tilesSize));
				
				tile->setName("Map");
				tile->setIsStatic(false);
				tile->setIsDrawing(true);
				tile->setAngle(0);
				tile->setFlip(FLIP(NONE));
				
				//Identity of values
				for(int k = 0; k < max_num + 1; k++)
					if(map->numbers[i][j] == k) 
					{
						tile->setCropPosition(Vector2<int>(k * map->tilesSize, 0));
						tile->setTile(k);
					}
					
				v.push_back(std::move(tile));
			}
			map->tiles.push_back(v);
		}
		
		//Returning width and height of map
		return Vector2<int>(map->tilesSize * map->width, map->tilesSize * map->height);
	}
	Sprite& Renderer::getSpriteById(std::string name)
	{
		for(auto &i : spriteVector)
		{
			if(i->getName() == name)
				return *i;
		}
	}
	Label& Renderer::getLabelById(std::string name)
	{
		for(auto &i : labelVector)
		{
			if(i->getName() == name)
				return *i;
		}
	}
	std::shared_ptr<Map> Renderer::getMap()
	{
		return map;
	}
}	
