package main

import (
	"fmt"
	"strconv"
)

type command interface {
	Execute() string
}

type MacroCommand struct {
	commands []command
}

func (self *MacroCommand) Execute() string {
	var result string
	for _, command := range self.commands {
		result += command.Execute() + "\n"
	}
	return result
}

func (self *MacroCommand) Append(command command) {
	self.commands = append(self.commands, command)
}

func (self *MacroCommand) Undo() {
	if len(self.commands) != 0 {
		self.commands = self.commands[:len(self.commands)-1]
	}
}

func (self *MacroCommand) Clear() {
	self.commands = []command{}
}

type Position struct {
	X, Y int
}

type DrawCommand struct {
	Position *Position
}

func (self *DrawCommand) Execute() string {
	return strconv.Itoa(self.Position.X) + "." + strconv.Itoa(self.Position.Y)
}

func main() {
	macro := MacroCommand{}

	macro.Append(&DrawCommand{&Position{1, 1}})
	macro.Append(&DrawCommand{&Position{2, 2}})

	expect := "1.1\n2.2\n"
	if macro.Execute() != expect {
		fmt.Println("Expect result to equal %s, but %s.\n", expect, macro.Execute())
	}

	macro.Undo()
	expect = "1.1\n"
	if macro.Execute() != expect {
		fmt.Println("Expect result to equal %s, but %s.\n", expect, macro.Execute())
	}
}
