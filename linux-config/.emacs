;; Dependencies
;; (add-to-list 'load-path (expand-file-name "~/.emacs.d/"))
;; (add-to-list 'load-path (expand-file-name "~/.emacs.d/cc-mode-5.32.5/"))
;; (require 'misc)

;; sometimes useful to disable
(add-hook 'before-save-hook 'delete-trailing-whitespace)

(add-hook 'c-mode-common-hook
          (lambda()
            (local-set-key (kbd "C-c <right>") 'hs-show-block)
            (local-set-key (kbd "C-c <left>")  'hs-hide-block)
            (local-set-key (kbd "C-c <up>")    'hs-hide-all)
            (local-set-key (kbd "C-c <down>")  'hs-show-all)
            (hs-minor-mode t)))

;; Basic settings
(setq shell-file-name "bash")
(setq shell-command-switch "-ic")
(if window-system (set-frame-size (selected-frame) 100 40))
(setq inhibit-splash-screen t)
(setq-default indent-tabs-mode nil)
(setq read-file-name-completion-ignore-case t)
(setq read-buffer-completion-ignore-case t)
(setq find-name-arg "-iname")
(setq line-number-mode t)
(delete-selection-mode 1)
(show-paren-mode 1)
(setq show-paren-delay 0)
(add-to-list 'default-frame-alist '(font . "Monospace-9"))
(global-auto-revert-mode t)
(setq-default cursor-type 'bar)
(setq split-height-threshold nil)
(menu-bar-mode -1)
(tool-bar-mode -1)
(scroll-bar-mode -1)
(column-number-mode t)
(line-number-mode t)
(fset 'yes-or-no-p 'y-or-n-p)
(global-hl-line-mode 1)
(setq x-select-enable-clipboard t)
(setq case-fold-search t)
(global-set-key (kbd "M-/") 'hippie-expand)
;;(setq compile-command "make NOLICENSE=1 ENV=gnu4.8-r8 -k -j16 >/dev/null")
(setq compile-command "make-r8 >/dev/null")
(setq grep-command "grep --color=always -R -nH -i -e ")
(setq window-min-width 0)
(setq compilation-ask-about-save nil)
;; (modify-syntax-entry ?_ "w" c++-mode-syntax-table)
;; (modify-syntax-entry ?_ "_")


;; Programming settings
(setq-default c-basic-offset 2)
(add-to-list 'auto-mode-alist '("\\.h\\'" . c++-mode))
;; (autoload 'd-mode "d-mode" "Major mode for editing D" t)
;; (add-to-list 'auto-mode-alist '("\\.d[i]?$" . d-mode))

;; (c-add-style "my-style"
;; 	     '("stroustrup"
;; 	       (indent-tabs-mode . nil)
;; 	       (c-basic-offset . 6)
;; 	       (c-offsets-alist . ((inline-open . 0)
;; 				   (brace-list-open . 0)
;; 				   (statement-case-open . +)))))

;; (defun my-c++-mode-hook ()
;;   (c-set-style "my-style")
;;   (auto-fill-mode)
;;   (c-toggle-auto-hungry-state 1))

;; (add-hook 'c++-mode-hook 'my-c++-mode-hook)



;; Print settings
(setq ps-paper-type 'a4
      ps-font-size 7.0
      ps-print-header nil
      ps-landscape-mode t
      ps-line-number t
      ps-spool-duplex nil
      pr-toggle-file-duplex nil
      ps-number-of-columns 2)


(defun change-major-mode-hook ()
  (modify-syntax-entry ?_ "_"))


(defun rename-file-and-buffer (new-name)
  "Renames both current buffer and file it's visiting to NEW-NAME."
  (interactive "sNew name: ")
  (let ((name (buffer-name))
        (filename (buffer-file-name)))
    (if (not filename)
        (message "Buffer '%s' is not visiting a file!" name)
      (if (get-buffer new-name)
          (message "A buffer named '%s' already exists!" new-name)
        (progn
          (rename-file name new-name 1)
          (rename-buffer new-name)
          (set-visited-file-name new-name)
          (set-buffer-modified-p nil))))))


(defun indent-buffer ()
  "Indents an entire buffer using the default intenting scheme."
  (interactive
   (save-excursion
     (delete-trailing-whitespace)
     (indent-region (point-min) (point-max) nil)
     (untabify (point-min) (point-max)))))

(global-set-key "\C-x\\" 'indent-buffer)


(defun occur-non-ascii ()
  "Find any non-ascii characters in the current buffer."
  (interactive)
  (occur "[^[:ascii:]]"))


(defun select-previous-window ()
  "Switch to the previous window"
  (interactive)
  (select-window (previous-window)))

(defun select-next-window ()
  "Switch to the next window"
  (interactive)
  (select-window (next-window)))

(global-set-key (kbd "\C-x p") 'select-previous-window)
(global-set-key (kbd "\C-x o") 'select-next-window)


(defun my-java-mode-hook ()
  (setq c-basic-offset 2))

(add-hook 'java-mode-hook 'my-java-mode-hook)


(defun toggle-fullscreen ()
  (interactive)
  (set-frame-parameter nil 'fullscreen (if (frame-parameter nil 'fullscreen) nil 'fullboth)))

(global-set-key [f11] 'toggle-fullscreen)


(defun comment-dwim-line (&optional arg)
  "Replacement for the comment-dwim command.
        If no region is selected and current line is not blank and we are not at the end of the line,
        then comment current line.
        Replaces default behaviour of comment-dwim, when it inserts comment at the end of the line."
  (interactive "*P")
  (comment-normalize-vars)
  (if (and (not (region-active-p)) (not (looking-at "[ \t]*$")))
      (comment-or-uncomment-region (line-beginning-position) (line-end-position))
    (comment-dwim arg)))

(global-set-key "\M-;" 'comment-dwim-line)


(defun match-parenthesis (arg)
  "Match the current character according to the syntax table.

You can define new \"parentheses\" (matching pairs).
Example: angle brackets. Add the following to your .emacs file:

	(modify-syntax-entry ?< \"(>\" )
	(modify-syntax-entry ?> \")<\" )

You can set hot keys to perform matching with one keystroke.
Example: f6 and Control-C 6.

	(global-set-key \"\\C-c6\" 'match-parenthesis)
	(global-set-key [f6] 'match-parenthesis)"
  (interactive "p")
  (let
      ((syntax (char-syntax (following-char))))
    (cond
     ((= syntax ?\()
      (forward-sexp 1) (backward-char))
     ((= syntax ?\))
      (forward-char) (backward-sexp 1))
     (t (message "No match"))
     )
    ))

(global-set-key "\C-c6" 'match-parenthesis)
(global-set-key [f6] 'match-parenthesis)


(defun rename-file-and-buffer (new-name)
  "Renames both current buffer and file it's visiting to NEW-NAME."
  (interactive "sNew name: ")
  (let ((name (buffer-name))
        (filename (buffer-file-name)))
    (if (not filename)
        (message "Buffer '%s' is not visiting a file!" name)
      (if (get-buffer new-name)
          (message "A buffer named '%s' already exists!" new-name)
        (progn
          (rename-file name new-name 1)
          (rename-buffer new-name)
          (set-visited-file-name new-name)
          (set-buffer-modified-p nil))))))


;; KEY BINDINGS


;; C++ header guards
(global-set-key [f12]
  		'(lambda ()
  		   (interactive)
  		   (if (buffer-file-name)
  		       (let*
  			   ((fName (file-name-nondirectory (file-name-sans-extension buffer-file-name)))
  			    (ifDef (concat "// -*- C++ -*-\n\n#ifndef _" fName "_h_" "\n#define _" fName "_h_" "\n"))
  			    (begin (point-marker))
  			    )
  			 (progn
                           ;; ;; If less then 5 characters are in the buffer, insert the class definition
  			   ;; (if (< (- (point-max) (point-min)) 5 )
  			   ;;     (progn
  			   ;;       (insert "\nclass " (capitalize fName) "{\npublic:\n\nprivate:\n\n};\n")
  			   ;;       (goto-char (point-min))
  			   ;;       (next-line-nomark 3)
  			   ;;       (setq begin (point-marker))
  			   ;;       )
  			   ;;   )

                           ;; Insert the Header Guard
  			   (goto-char (point-min))
  			   (insert ifDef)
  			   (goto-char (point-max))
  			   (insert "\n#endif" " // _" fName "_h_")
  			   (goto-char begin))
  			 )
                     ;; else
  		     (message (concat "Buffer " (buffer-name) " must have a filename"))
  		     )
  		   )
  		)


;; C++ print statement
(global-set-key (kbd "\C-p")
  		'(lambda ()
  		   (interactive)
                   (insert "std::cout <<  << std::endl;")
                   (backward-char 14)))


;; Common keystrokes
(global-set-key [kp-home]  'beginning-of-buffer)
(global-set-key [kp-end]   'end-of-buffer)

;; (global-set-key [home]     'beginning-of-line)
;; (global-set-key [end]      'end-of-line)

;; (global-set-key [kp-prior] 'scroll-down)
;; (global-set-key [kp-next]  'scroll-up)

;; (global-set-key [prior]    'scroll-down)
;; (global-set-key [next]     'scroll-up)

(global-set-key [kp-subtract] 'undo)

;; (global-set-key "\C-w" 'kill-region)         ; Cut
;; (global-set-key "\M-w" 'copy-region-as-kill) ; Copy
;; (global-set-key "\C-y" 'yank)                ; Paste

;; (global-set-key [f2] 'split-window-vertically)
;; (global-set-key [f1] 'remove-split)
;; (global-set-key "\C-l" 'goto-line)
;; (global-set-key "\C-f" 'make-frame)
;; (global-set-key "\M-f" 'delete-frame)

;; mark ring
(global-set-key "\M-f" "\C-u1\C-v")
(global-set-key "\M-b" "\C-u1\M-v")


;; FONT SETTINGS

(global-font-lock-mode t)

(setq font-lock-maximum-decoration 3
      font-lock-maximum-size nil)

(setq font-lock-support-mode 'jit-lock-mode)
(setq jit-lock-stealth-time 16
      jit-lock-defer-contextually t
      jit-lock-stealth-nice 0.5)
(setq-default font-lock-multiline t)

(custom-set-faces
 '(font-lock-builtin-face ((t (:foreground "black"))))
 '(font-lock-comment-face ((t (:foreground "gray30" :italic t))))
 '(font-lock-constant-face ((t (:foreground "black"))))
 '(font-lock-string-face ((t (:foreground "red3"))))
 '(font-lock-type-face ((t (:foreground "blue"))))
 '(font-lock-function-name-face ((t (:foreground "black"))))
 '(font-lock-variable-name-face ((t (:foreground "black"))))
 '(font-lock-keyword-face ((t (:foreground "black" :weight bold))))
 '(font-lock-negation-char-face ((t (:foreground "orange3"))))
 '(font-lock-preprocessor-face ((t (:foreground "dark green"))))
 '(font-lock-warning-face ((t (:foreground "FireBrick"))))
 '(font-lock-comment-delimiter-face ((t (:inherit font-lock-comment-face))))
 '(font-lock-doc-face ((t (:inherit font-lock-string-face))))
 '(font-lock-doc-string-face ((t (:inherit font-lock-string-face))))
 )


;; (defun font-lock-fontify-numbers ()
;;   "Use this function as a hook to fontify numbers as constant"
;;   (font-lock-add-keywords nil
;;       '(("\\b\\(0x[0-9a-fA-F]+\\)" 1 font-lock-constant-face)
;;         ("\\b\\(-?[0-9]+\\.[0-9]+\\(d\\|f\\)?\\)" 1
;;          font-lock-constant-face) ; float
;;         ("[\`^\(){\[,\+\\-\\*/\%><=\s-]\\(-?[0-9]+U?L?L?\\)" 1
;;          font-lock-constant-face))))

;; (add-hook 'font-lock-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'c-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'c++-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'lisp-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'lisp-interaction-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'emacs-lisp-mode-hook 'font-lock-fontify-numbers
;; (add-hook 'html-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'xml-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'css-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'perl-mode-hook 'font-lock-fontify-numbers)
;; (add-hook 'sh-mode-hook 'font-lock-fontify-numbers)


;; Modernity


;; Cursor
(global-hl-line-mode 1) ; turn on highlighting current line
(set-face-background hl-line-face "gray95")

;; (electric-pair-mode 1)

(show-paren-mode 1) ; turn on paren match highlighting
(setq show-paren-style 'expression) ; highlight entire bracket expression
(setq show-paren-delay 0)
(set-face-background 'show-paren-match-face "gray90")
;; (set-face-foreground 'show-paren-match-face "#def")
;; (set-face-attribute 'show-paren-match-face nil :weight 'extra-bold)


(cua-mode 1) ; cut, copy, paste
(transient-mark-mode 1) ; highlight text selection
(delete-selection-mode 1) ; delete seleted text when typing
(global-font-lock-mode 1) ; turn on syntax coloring

;; (global-linum-mode 1) ; display line numbers in margin. Emacs 23 only.
(column-number-mode 1)
(recentf-mode 1) ; keep a list of recently opened files
;; (setq line-move-visual nil) ; use t for true, nil for false
;; (global-visual-line-mode 1) ; 1 for on, 0 for off.



(cua-mode t)
(setq cua-auto-tabify-rectangles nil)
(setq cua-keep-region-after-copy nil)
(transient-mark-mode t)
(delete-selection-mode t)
