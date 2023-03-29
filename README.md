# LowLevelGameEngine



## What is it?
	
It is the official game engine developed by the Low Level Game Dev community .

* [Youtube](https://www.youtube.com/channel/UChkC4u4KdnIDFh9hPqExLDg)
* [Discord](https://discord.gg/eehehsPAka)

---

## Why?

It is a place where everyone can learn some game programming. **Everyone** can contribute to this engine, no matter the programming experience. If you are a beginner and you can think of a simple feature that this engine might need you are free to add it to the engine.

---

## How Can I join?

Join our [Discord](https://discord.gg/eehehsPAka) server and there in the LowLevelGameEngine channel you can apply.

---

## How to contribute to the engine?

First are some basic rules that you have to fallow but in a nutshell we will try to be disorganized in an organized manner. 

- Branches: Since everyone can bring contributions we want to avoid collisions. Use branches and pull requests when merging on master and not work on the master branch and have a branch for each feature. 

- Components:  Let's split the engine into individual components so it is easier to work in parallel.

- Keep things hand-made: It would be easy to add a library that prints and formats logs to the console but why do that when a beginner would love to implement that task. Let's try to implement as many things by hand as we can and use libraries only for difficult stuff.

- Let's write new things: You might have your own libraries, I already have mine but let's have fun and re-write things from scratch.

- Cross platform: let's try to make the engine work both on Windows and Linux, if you have a feature that could only work on Windows that is ok as long as you make sure that it still compiles on Linux (have some macros that disable your feature on Linux). The same goes for Linux specific features.

## Rules

- Respect others.
- Don't randomly delete things.
- Don't use racist or hate words in code.

## Components

- There is a component example in the repo as a template.

- You can aces other components (by linking to them in the CMake) but this gives us the problem that people now have to maintain compatibility with every other component linked to them. To keep things simple if you want to aces another component just message on discord someone that works on that component to talk about the feature that you want to add to see if there are problems that might appear.
 
- If you are a major contributor to a component you should add a discord contact in the README file of that component so that people can contact you on discord.

## Coding Style

	Paranthases:
	
	```
	void main()
	{
		if(stuff)
		{
		}
	}
	```
>	
	CammelCase:
	
	```
	int variable;
	void function();
	struct MyStruct();
	void MyStruct::myMethod();
	```

>
	Use namespaces for components.

>
	Try to use comments where necessary. 
	Don't use comments in places where they are not needed. 
>
	Try to have a clean API when designing your components. 
	A clean api is an api that doesn't let the user do something that can fail, and comment how your functions are supposed to be used if it is not self evident.
>
	Don't have too of a oop approach, we will try to have a data oriented design. You can use some incapsulation when designing the components api.

>
	Don't use polimorfism and don't abuse heap allocations.

>
	Components that need to allocate memory should have a create function rather than a constructor and a cleanup function that will be called by hand. Implementing a RAII class like a std::vector can have too many pitfalls so let's keep things simple.
