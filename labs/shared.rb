require 'Contracts'
require 'Html'

module Quiz
  extend Html::Generation::Quiz
end


class Counter
  def initialize
    @last = 0
  end

  def next
    @last += 1
  end
end


class InterpretationExerciseContext
  include Contracts::TypeChecking

  attr_accessor :source, :input, :output
  
  def show_source_editor(**opts)
    typecheck do
      assert(source: string)
    end
    
    Html::Generation.source_editor(source, **opts)
  end

  def show_input
    typecheck do
      assert(input: string)
    end
    
    %{<p>Input: <code>#{input}</code></p>}
  end

  def compute_output
    typecheck do
      assert(source: string, output: string | value(nil))
    end
    
    self.output = Cpp.compile_and_run_source(source, input: input).strip
  end

  def show_output_field(auto_compute: true)
    if !output && auto_compute then
      compute_output
    end

    out = output
    %{<p>Output: #{Quiz.validated_input { verbatim out }}</p>}
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

  def format_exercise(index: increment_exercise_counter)
    typecheck do
      assert(index: integer & positive)
    end

    <<-END
    <section class="question">
      <h1>Exercise #{index}</h1>
      #{yield}
    </section>
    END
  end

end
