\NeedsTeXFormat{LaTeX2e}
\ProvidesPackage{ucll-exam}[04/07/2014]
\LoadClass{scrartcl}

\RequirePackage[paper=a4paper,headheight=1.2cm,top=2cm,bottom=1.5cm,includeheadfoot]{geometry}
\RequirePackage{scrpage2}
\RequirePackage{afterpage}
\RequirePackage{tabularx}
\RequirePackage{booktabs}
\RequirePackage{graphicx}
\RequirePackage{multirow}
\RequirePackage{microtype}
\RequirePackage{lastpage}
\RequirePackage{tikz}
\RequirePackage{siunitx}
\RequirePackage{amsmath}
\RequirePackage{amsfonts}
\RequirePackage[utf8]{inputenc}
\RequirePackage{stmaryrd}
\RequirePackage{marvosym}
\RequirePackage{framed}
\RequirePackage{etoolbox}
\RequirePackage{comment}

\usetikzlibrary{intersections,calc,math}


\newtoggle{showsolution}

\ProcessOptions\relax

\newcommand{\SOL}[2]{\iftoggle{showsolution}{#2}{#1}}

\ifdefined\solution\toggletrue{showsolution}\else\togglefalse{showsolution}\fi


\tikzset{
  /ucll/showif/show/.initial=yes
}

\newcommand{\showif@always}[1]{#1}
\newcommand{\showif@solution}[1]{\SOL{}{#1}}


\newcommand{\showif}[2][]{%
  {%
    \tikzset{/ucll/showif/.cd,#1,show/.get=\showbox@show}%
    \csname showif@\showbox@show\endcsname{#2}%
  }
}


\newpagestyle{exampage}{%
  {\smallheader@produce}%
  {\smallheader@produce}%
  {\smallheader@produce}
  (\textwidth,1pt)
}{%
  {L}%
  {R}%
  {\normalfont\rlap{\exam@datum} \hspace{\fill} Pagina \thepage\ van \pageref{LastPage}}%
}

\newpagestyle{firstexampage}{%
  {\header@produce}%
  {\header@produce}%
  {\header@produce}
  (\textwidth,1pt)
}{%
  {L}%
  {R}%
  {\normalfont\rlap{\exam@datum} \hspace{\fill} Pagina \thepage\ van \pageref{LastPage}}%
}

\pagestyle{exampage}

\AtBeginDocument{
  \thispagestyle{firstexampage}
}

\pgfkeys{
  /exam/.cd,
  academiejaar/.store in=\exam@academiejaar,
  opleiding/.store in=\exam@opleiding,
  fase/.store in=\exam@fase,
  examinator/.store in=\exam@examinator,
  opo/.store in=\exam@opo,
  ola/.store in=\exam@ola,
  activiteit/.store in=\exam@activiteit,
  hulpmiddelen/.store in=\exam@hulpmiddelen,
  datum/.store in=\exam@datum,
  beginuur/.store in=\exam@beginuur,
  duur/.store in=\exam@duur
}

\pgfkeys{
  /exam/fill in/.cd,
  width/.initial={2cm},
  depth/.initial={-3mm},
  height/.initial={5mm},
  thickness/.initial={.5pt},
  solution fit width flag/.initial=0,
  solution fit width/.style={/exam/fill in/solution fit width flag=1},
  fit height/.style={/exam/fill in/height=0}
}

\newcommand{\blank}[2]{\makebox[#1]{\iftoggle{showsolution}{{#2}}{\hrulefill}}}
\newcommand{\exam}[1]{\pgfkeys{/exam/.cd,#1}}

\newcommand{\header@produce}{%
  \footnotesize\normalfont%
  \begin{tabular}{rlr}
    Academiejaar: & \exam@academiejaar & \multirow{4}{2cm}[0mm]{\includegraphics[width=3cm]{ucll-logo.png}} \\
    Opleiding: & \exam@opleiding  & \\
    Fase: & \exam@fase  & \\
    Examinator: & \exam@examinator  & \\
    OPO: & \exam@opo  & \\
    OLA: & \exam@ola  & \\
    Activiteit:& \exam@activiteit &\\
    Hulpmiddelen: &\exam@hulpmiddelen & \\ 
    Datum: & \exam@datum &  \\
    Beginuur: & \exam@beginuur & \\
    Tijdsduur: & \exam@duur  & \\ \\
    Student: & \multicolumn{2}{l}{\parbox{5cm}{\dotfill} \hspace{1mm} Nummer: \parbox{2cm}{\dotfill} \hspace{1mm} Reeks: \parbox{1cm}{\dotfill}}
  \end{tabular}%
}

\newcommand{\smallheader@produce}{
  \footnotesize\normalfont\hspace*{\fill}
  \begin{tabular}{rlr}
    OLA: & \exam@ola  & \\
    Datum: & \exam@datum &  \\[2mm]
    Student: & \multicolumn{2}{l}{\parbox[b][.5cm][b]{9cm}{\dotfill} \hspace{1mm} \hspace{1mm} Reeks: \parbox[b][.5cm][b]{1cm}{\dotfill}}
 \end{tabular}\hspace*{\fill}%
}




\newcommand{\MAINHEADER}{\header@produce}
\newcommand{\HEADER}{\smallheader@produce}


\newcounter{questioncounter}


\pgfkeys{
  /question/.cd,
  oral/.initial={0}
}
\newenvironment{question}[1][]{
  \begin{center}
  \begin{minipage}{.95\linewidth}
    \pgfkeys{
      /question/.cd,
      #1,
    }
    \begin{center}
      \fbox{\parbox[c][1cm][c]{.8\linewidth}{\centering\Large\textsc{Vraag \stepcounter{questioncounter}\arabic{questioncounter}}}}
    \end{center}
}{
  \end{minipage}
  \end{center}
}

\iftoggle{showsolution}{\includecomment{solution}}{\excludecomment{solution}}
\iftoggle{showsolution}{\excludecomment{sheet}}{\includecomment{sheet}}


\newcommand{\Z}{\mathbb{Z}}
\newcommand{\real}{\mathbb{R}}
\newcommand{\+}[1]{\mathrm{#1}}
\newcommand{\R}{\+{R}}
\newcommand{\G}{\+{G}}
\newcommand{\B}{\+{B}}
\newcommand{\norm}[1]{|#1|}
\newcommand{\conj}[1]{#1^*}
\newcommand{\transpose}[1]{#1^{\mathrm{T}}}
\newcommand{\inverse}[1]{#1^{-1}}
\newcommand{\degrees}{\ensuremath{^{\circ}}}
\newcommand{\colorrgb}[3]{\ensuremath{({\color{red}#1},{\color{green}#2},{\color{blue}#3})}}


\tikzset{
  vector/.style={-latex,thick},
  light/.style={-latex,thick,orange},
  axis/.style={-latex,thick}
}

\newcommand{\blanks}[1]{
  \begin{center}
    \begin{tikzpicture}
      \foreach \y in {0,...,#1} {
        \draw[thin,black!50] (0,\y) -- ++(14,0);
      }
    \end{tikzpicture}
  \end{center}
}