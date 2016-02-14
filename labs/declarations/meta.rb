require 'MetaData'
require 'Html'
require 'Code'
require 'Cpp'
require 'Upload'
require 'Html'
require 'pathname'


module Quiz
  extend Html::Generation::Quiz
end


class Context
  include Contracts::TypeChecking
  include Html::Generation


  def compile(path)
    typecheck do
      assert(path: file)
    end

    Cpp.compile(path)
  end

  def interpret_exercise(source, input: nil)
    typecheck do
      assert(source: string)
    end

    source_path = Pathname.new 'temp.cpp'
    executable_path = Pathname.new 'temp.exe'
    
    File.open(source_path, 'w') do |out|
      out.puts source
    end
    
    Cpp.compile source_path

    if input
      output = `echo #{input} | #{executable_path}`.strip
      input_message = %{<p>Input: <code>#{input}</code></p>}
    else
      output = `#{executable_path}`.strip
      input_message = ""
    end

    <<-END
    <section class="interpretation-question">
      <h1>Interpretation Exercise</h1>
      <p>What is the output of the following code?</p>
      <div class="code"><pre>#{Code.format_file(source_path).strip}</pre></div>
      #{input_message}
      <p>Output: #{Quiz.validated_input { verbatim output }}</p>
    </section>
    END
  end
end


meta_object do
  extend MetaData::Actions
  extend Html::Actions
  extend Upload::Mixin

  def remote_directory
    world.parent.remote_directory
  end

  html_template('assignment', context: Context.new, group_name: 'html')
  
  uploadable('assignment.html')
  upload_action

  group_action(:full, [:upload])
end
