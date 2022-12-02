<?php
class B
{
  // Members
  // A private member named "j" who has type integer 'int'
  private $j , $k;

  // Constructors
  // NOTICE: in php, a constructor is always declared as a function, but
  // in other object oriented languages, it is not the case.
  // in PHP a constructor is always declared with the keyword __construct(...)
    public function __construct(int $_j, int $_k) {
    $this->setJ($_j);
    $this->setK($_k);

  }

  // Getters
  public function getJ() {
    return ($this)->j;
  }
  public function getK() {
    return ($this)->k;
  }


  // Setters
  public function setJ(int $_j){
    ($this)->j = $_j;
  }
  public function setK(int $_k){
    ($this)->k = $_k;
  }

  // Helpers
  public function myPrint()
  {
    echo "----------IN PARENT CLASS----------"
    	. "<BR>"
    	. "my j in B is : "
    	. $this->getJ()
        . "<BR>"
    	. "my k in B is : "
    	. $this->getK();
  }
}

class A extends B
{
  // Members
  // A private member named "i" who has type integer 'int'
  private $i;


  // Constructors
  // NOTICE: in php, a constructor is always declared as a function, but
  // in other object oriented languages, it is not the case.
  // in PHP a constructor is always declared with the keyword __construct(...)
    public function __construct(int $_i, int $_j, int $_k) {
      parent::__construct($_j, $_k);
      $this->setI($_i);
  }

  // Getters
  public function getI() {
    return ($this)->i;
  }

  // Setters
  public function setI(int $_i){
    ($this)->i = $_i;
  }

  // Helpers
  public function myPrint()
  {
    echo "----------IN CHILD CLASS----------"
    	. "<BR>"
    	. "My i in A is : "
    	. $this->getI()
        . "<BR>"
        . "My j in A (j here is referred
        	to be the member of the parent class B), is : "
        . $this->getJ()
        . "<BR>"
        . "My k in A (k here is referred
        	to be the member of the parent class B), is : "
        . $this->getK();
  }
}

// The call of the constructor: instantiation of object myinstanceofa of class A
$myinstanceofa = new A(1, 2, 3);


// The call of the constructor: instantiation of object myinstanceofb of class B
$myinstanceofb = new B(4,5);

// The call of the helper method myPrint()
$myinstanceofa->myPrint();

echo "<br>";
echo "<br>";


// The call of the helper method myPrint()
$myinstanceofb->myPrint();
?>
