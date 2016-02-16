require 'Html'
require 'Html'


class Counter
  def initialize
    @last = 0
  end

  def next
    @last += 1
  end
end


class SharedContext
  include Contracts::TypeChecking
  include Html::Generation

  def self.create_counter(symbol)
    instance_variable = "@#{symbol.to_s}"

    define_method symbol do
      counter = instance_variable_get(instance_variable)

      unless counter then
        instance_variable_set(instance_variable, counter = Counter.new)
      end

      counter
    end      
  end

  create_counter :source_editor_counter

  def source_editor(source)
    typecheck do
      assert(source: string)
    end

    source = Html.escape(Code.remove_redundant_indentation(source)).strip

    %{<div class="source-editor" id="code#{source_editor_counter.next}"><pre>#{source}</pre></div>}
  end
end
