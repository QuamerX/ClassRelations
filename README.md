# Class Relation Types

This document describes the main types of relationships that can exist between classes in object-oriented design. Each defines a specific way classes are connected, depend on each other, or share responsibility.

---

## 1. Inheritance
A relationship where one class (the subclass) derives from another class (the superclass).  
The subclass inherits attributes and behaviors, allowing reuse and extension of existing functionality.  
**Represents:** “is-a” relationship.  
**Example meaning:** A `Dog` is an `Animal`.

---

## 2. Implementation
A relationship between a class and an interface (or abstract class).  
The class provides concrete definitions for the abstract behaviors defined by the interface.  
**Represents:** “implements” relationship.  
**Example meaning:** A `Circle` implements the `Shape` interface.

---

## 3. Association
A general relationship showing that one class is connected to another.  
Each class can exist independently, but they are aware of or use each other in some way.  
**Represents:** “uses” or “knows” relationship.  

### a. One-to-One
Each object of one class is linked to exactly one object of another class.  
**Example meaning:** A `Person` has one `Passport`.

### b. One-to-Many
One object of a class is linked to multiple objects of another class.  
**Example meaning:** A `Library` has many `Books`.

### c. Many-to-Many
Objects from both classes can be linked to multiple instances of the other.  
**Example meaning:** A `Student` attends many `Courses`, and each `Course` has many `Students`.

---

## 4. Aggregation
A “whole-part” relationship where the part can exist independently of the whole.  
The containing object references the other but does not control its lifetime.  
**Represents:** “has-a” (weak ownership).  
**Example meaning:** A `Department` has `Employees`, but `Employees` can exist without the `Department`.

---

## 5. Composition
A strong “whole-part” relationship where the part cannot exist without the whole.  
The contained object’s lifetime is managed entirely by the container.  
**Represents:** “has-a” (strong ownership).  
**Example meaning:** A `Car` is composed of an `Engine`, and when the `Car` is destroyed, so is the `Engine`.

---

## 6. Dependency
A temporary relationship where one class depends on another for a specific operation or behavior.  
Usually occurs when a class uses another as a parameter or within a method.  
**Represents:** “depends on” relationship.  
**Example meaning:** A `Printer` depends on a `Document` to perform printing.

---

### Summary Table

| Relation Type   | Lifetime Link | Ownership Strength | Example Meaning             |
|------------------|----------------|---------------------|-----------------------------|
| Inheritance      | Permanent       | Strong              | *is-a*                     |
| Implementation   | Permanent       | Strong              | *implements*               |
| Association      | Independent     | Weak                | *uses / knows*             |
| Aggregation      | Independent     | Weak                | *has-a (shared)*           |
| Composition      | Dependent       | Strong              | *has-a (owned)*            |
| Dependency       | Temporary       | None                | *depends on*               |

---

**Purpose:**  
Provide a concise conceptual overview of class relationship types used in object-oriented design.
