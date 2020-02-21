/* 
 * File:   main.cpp
 * Author: papa
 *
 * Created on 21 февраля 2020 г., 7:27
 */
#include <iostream>
#include <string>
#include <fstream>
#include "utilMacr.h"
/*(!)
 * рус: Основная идея, выполнение промежуточного текстового языка так называемого
 * ITLWM(Intermediate text language of Wol Vm)
 * en: The main idea is execution of intermidiate text language as we call ITLWM(Intermediate text language of Wol Vm)
 * 
 */
using namespace std;
const string version = "1.0.0.0"; //need for future frameworks
const string info = "World of Legends Virtual Machine Native\nVersion: " + version + "\nAuthors Alexander Gunge, Muhamedjanov Konstantin  K."; //need for future frameworks
const string help = "World of Legends Virtual Machine v" + version + " Helper\n" +
	+"\nArguments:\n";
void Run(string input);
/**
 * рус: В основном должен принимать текстовый файл программы - ITLWM(Intermediate text language of Wol Vm)
 * en: mainly accept text file of program - ITLWM(Intermediate text language of Wol Vm)
 * @param argc - количество аргументов | amount of arguments
 * @param argv - вектор строк | vector of strings
 * @return - код успеха | success code
 */
#define buf_for_itlwm_keyword 10
int main(int argc, char* argv[]) {
	if (argc == 1)
		cout << info;
        else $
		if (!strcmp(argv[1], "-info"))
			cout << info;
		 else if (!strcmp(argv[1], "-help") || !strcmp(argv[1], "--help"))
			cout << help,
			cout <<"Usage: <exe> <itlwm_text_file>.bld" << endl;
		 else if (!strcmp(argv[1], "-encode"))
			cout << "Sorry, while this option is this version in develop";
		 else $
			ifstream input(argv[1]); //открываем файл | open get file
			S code = "", line;
			if (input.is_open())$
				while (getline(input, line))
					code += line; //добавляем строку к коду|add line of file to code
			        $$
			input.close(); // закрываем файл | close file
		        $$
	                $$
	_0_("main");
}
class Stack{
};
/* рус: Метод где мы анализиреум исходный код ITLWM(Intermediate text language
 * of Wol Vm), создаем оььекты на стеке.
 * en: Methon where we parse(analize) source of ITLWM(Intermediate text language
 * of Wol Vm), create objects on stack.
 */
/**
 * Выполнение
 * Execution
 * @param mainstack обьект стека | stack object
 * @param input исходный код itlwm типа строки | source code of itlwm as string
 */
void Run(Stack *mainstack,S input) {
	/* Скопировал charp
	 */
	/*
	//add base classes to stack                 parents:
	mainstack->classes.Add("void", new Void()); //no
	mainstack->classes.Add("byte", new wolByte()); //void
	mainstack->classes.Add("short", new wolShort()); //byte
	mainstack->classes.Add("string", new wolString()); //void
	mainstack->classes.Add("int", new wolInt()); //short
	mainstack->classes.Add("float", new wolFloat()); //int
	mainstack->classes.Add("long", new wolLong()); //int
	mainstack->classes.Add("double", new wolDouble()); //float
	mainstack->classes.Add("Type", new wolType()); //void
	mainstack->classes.Add("Func", new wolFunc()); //void
	mainstack->classes.Add("Enum", new wolEnum()); //void
	mainstack->classes.Add("char", new wolChar()); //void
	mainstack->classes.Add("Block", new wolBlock()); //void
	mainstack->classes.Add("Collection", new wolCollection()); //void
	mainstack->classes.Add("Array", new wolArray()); //Collection
	mainstack->classes.Add("Link", new wolLink()); //void
	mainstack->classes.Add("bool", new wolBool()); //void
        */
	//основной цикл | main cycle
        I position;
	c current;
	position = 0;
	current = input[0];
	// буффер для ключевых слов itlwm | buffer for keywords of itlwm
	c kw_buf[buf_for_itlwm_keyword];
	I cn_kw=0;
	I time = Environment.TickCount;
	// парсим весь исходный код
	// parsing of whole source code
	while (position < input.size())$
		while (current==' ')$ //пропускаем пробелы|skip whitespaces
			position++;
			if (position > input.size())
				cout<<"Build-file have only whitespaces", position, ExceptionType.BLDSyntaxException,
				return;
			current = input[position];
		        $$ 
		while (current!=' ')$ //образовываем текстовые слова|get word
			// добавляем символ | add symbol
			kw_buf[cn_kw]=current;
			// считаем символы | count symbols
			cn_kw++;
			// Идем по буквам текста itlwm | go forward on itlwm text
			position++;
			/*
			try
			{
				current = input[position];
			} catch (IndexOutOfRangeException)
			{
				cout<<"Build-file have only one word"<< position<< ExceptionType.BLDSyntaxException;
				return;
			}
			 */
		        $$ //свернули слово,затем анализируем его|convoluted the word, than analize it]
		// образовываем слово | complete the word		
		kw_buf[cn_kw+1]='\0';		
		// начинаем анализ(этого слова)| begin analize(of this word)		
		if (!strcmp(kw_buf "_loads"))$
			// зачистить буффер слов | clear words buffer
		        cn_kw=0;
			while (current==' ')$
				position++;
				if (position > input.size())
					cout<<"Start of loads struct not found"<<position<< ExceptionType.BLDSyntaxException,
					return;
				current = input[position];
			        $$
			if (current == '{')$
				// зачистить буффер слов | clear words buffer
		                cn_kw=0;
				while (current != '}')$ // получить 'тело' loads | get loads body
					kw_buf[cn_kw]=current;
					position++;
					if (position > input.size())
						cout<<"End of loads struct not found"<< position/*, ExceptionType.BLDSyntaxException)*/,
						return;
					current = input[position];
                                        $$ 
				// удалить скобку ({) | delete bracket ({)
		                kw_buf[0]=' ';				
				//начинаем парсить инструкцию loads|start parse loads
				/*string dllSource = buffer.ToString();
				Type mainType = typeof(VMLibrary);
				List<string> dllNames = dllSource.Split(';').ToList();
				foreach(string dllName in dllNames) {
					Assembly assembly = null;
					string full_path = AppDomain.CurrentDomain.BaseDirectory + dllName.Trim() + ".dll";
					try
					{
						assembly = Assembly.LoadFrom(full_path);
					} catch (Exception ex)
					{
						cout<<"Library with info {full_path} not found.\n{ex.Message}"<< position, ExceptionType.FileNotFoundException;
						break;
					}
					Type mainClass = assembly.GetTypes().FirstOrDefault(t = > t != mainType && mainType.IsAssignableFrom(t));
					if (test)
					{
						Console.WriteLine("Framework Info: " + assembly);
						Console.WriteLine("Full path to framework: " + full_path);
						Console.WriteLine(string.Join<Type>(' ', assembly.GetTypes()));
					}
					if (mainClass != null)
					{
						if (Activator.CreateInstance(mainClass) is VMLibrary mainObj) mainObj.Load();
						else cout<<($"Main class in library by name {dllName} haven`t type VMLibrary and will cannot loaded", position, ExceptionType.LoadsException);
					} else
					{
						cout<<($"Library by name {dllName} haven`t main class and will cannot loaded", position, ExceptionType.LoadsException);
					}
				}*/
				//конец парсинга текстовой инструкции loads|end parse loads
			        $$
			else
				cout<<"Start of loads struct not found"<< position/*<< ExceptionType.BLDSyntaxException*/;
                                $$
		else if (!strcmp(kw_buf, "stack"))$
			buffer.Clear();
			while (char.IsWhiteSpace(current))
			{
				position++;
				if (position > input.Length)
				{
					cout<<"Start of stack not found"<< position/*<< ExceptionType.BLDSyntaxException*/;
					return;
				}
				current = input[position];
			}
			if (current == '{')
			{
cycle:
				while (current != '}') //get stack body
				{
					buffer.Append(current);
					position++;
					if (position > input.Length)
					{
						cout<<"End of stack not found"<< position/*<< ExceptionType.BLDSyntaxException*/;
						return;
					}
					current = input[position];
				}
				if (input[++position] == ';')
				{
					buffer.Append(current);
					current = input[position];
					goto cycle;
				}
				mainstack.Add(Stack.Parse(buffer.ToString().Trim()));
			} else
			{
				cout<<("Start of stack not found", position<< ExceptionType.BLDSyntaxException;
			}
			position--;
		$$ 
		else if (buffer.ToString() == "main")
		{
			buffer.Clear();
			while (char.IsWhiteSpace(current))
			{
				position++;
				if (position > input.Length)
				{
					cout<<"Start of script not found"<< position<< ExceptionType.BLDSyntaxException);
					return;
				}
				current = input[position];
			}
			if (current == '{')
			{
				while (current != '}') //get script
				{
					buffer.Append(current);
					position++;
					if (position > input.Length)
					{
						cout<<("End of script not found", position, ExceptionType.BLDSyntaxException);
						return;
					}
					current = input[position];
				}
				Script.Parse(buffer.ToString().Trim().Remove(0, 1));
			} else
			{
				cout<<("Start of script not found", position, ExceptionType.BLDSyntaxException);
			}
		} else if (buffer.ToString() == "end")
		{
			if (test)
			{
				//тестируем стек|test stack
				Console.WriteLine("Info about program in the end.\nMain stack:");
				Console.WriteLine(mainstack.ToString());
				Console.WriteLine("Expressions:");
				foreach(string expr_name in expressions.Keys) {
					Console.WriteLine(expr_name);
				}
				Console.WriteLine($"Time of program: {Environment.TickCount - time}");
			}
			return;
		 else if (buffer.ToString() == "}")
			position++,
			continue;
		 else
			cout<<"Unknown keyword {buffer.ToString()}", position, ExceptionType.BLDSyntaxException;
	        $$
}
