class Father():
    name = 'Robert'

class Person(Father):
    def __init__(self, name):
        self.fathername = super().name
        self.name = name
        pass
    
    def introduce(self):
        print(f"My name is {self.name}, son of {self.fathername}")

king = Person("Joffrey")
king.introduce()