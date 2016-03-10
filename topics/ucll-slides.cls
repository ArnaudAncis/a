\NeedsTeXFormat{LaTeX2e}
\ProvidesPackage{ucll-slides}[16/05/2014]
\LoadClass{beamer}

\RequirePackage{graphicx}
\RequirePackage{pxfonts}
\RequirePackage{tikz}
\RequirePackage{calc}
\RequirePackage{listings}
\RequirePackage{booktabs}
\RequirePackage{url}
\RequirePackage{framed}
\RequirePackage{hyperref}
\RequirePackage{cleveref}
\RequirePackage{bbding}
\RequirePackage{wasysym}

\usetikzlibrary{shadows,calc,shapes}


\mode<presentation>
\usetheme[height=.75cm]{Singapore}
% \setbeamertemplate{background canvas}[vertical shading][top=blue!10,bottom=blue!30]

\institute[UCLL]{UC Leuven Limburg}
% \logo{\includegraphics[height=0.5cm]{../ucll-logo.png}}


% Code formatting
\pgfkeys{
  /ucll/code/.cd,
  frame/.code=\lstset{frame=#1},
  font size/.code=\lstset{basicstyle={\ttfamily #1}},
  width/.initial=.8\linewidth,
  language/.code=\lstset{language=#1},
  show lines/.code=\lstset{showlines},
  title/.code=\lstset{title=#1},
}

\lstset{language=c++,escapeinside=\`\`,basicstyle=\ttfamily}

% \code[pgfkeys]{filename}
\newcommand{\code}[2][]{
  {
    \pgfkeys{/ucll/code/.cd,#1}
    \begin{center}
      \pgfkeys{/ucll/code/width/.get=\code@width}
      \begin{minipage}{\code@width}
        \lstinputlisting{#2}
      \end{minipage}
    \end{center}
  }
}

\newcommand{\inlinecode}[2][]{
  {
    \pgfkeys{/ucll/code/.cd,#1}
    \pgfkeys{/ucll/code/width/.get=\width}
    \begin{minipage}{\width}
      \lstinputlisting{#2}
    \end{minipage}
  }
}


% Tikz related commands
% \NODE{text}{id}
\newcommand{\NODE}[3][]{\tikz[baseline,remember picture]{\node[anchor=base,inner sep=0mm,#1] (#3) {{#2}};}}



\newcommand{\toc}{
  \begin{frame}
    \tableofcontents[sectionstyle=show/shaded,subsectionstyle=show/shaded/hide]
  \end{frame}
}


\setbeamertemplate{title page}{%
  \begin{center}
    PVM \\[5mm]
    {\sc\Huge \inserttitle}
  \end{center}
}

\newcommand{\link}[2]{\href{#1}{{\color{blue}#2}}}

\newenvironment{procontralist}{
  \begingroup
  \newcommand{\pro}{\item[\Checkmark]}
  \newcommand{\con}{\item[\XSolidBrush]}
  \begin{itemize}
  }{
  \end{itemize}
  \endgroup}
