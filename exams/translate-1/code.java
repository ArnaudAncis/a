interface Readable {
  String read();
}

interface Writeable {
  void write(String value);
}

class Property implements Readable, Writeable {
  private String value;

  public Property() {
      this("");
  }

  public Property(String value) {
      this.value = value;
  }

  public Property(Property property) {
      this(property.value);
  }

  public String read() {
      return value;
  }

  public void write(String value) {
      this.value = value;
  }
}
