/////////////////////////////////////////////////////////////////////////////
// Name:        validate.h
// Purpose:     interface of wxValidator
// Author:      wxWidgets team
// RCS-ID:      $Id$
// Licence:     wxWindows license
/////////////////////////////////////////////////////////////////////////////

/**
    @class wxValidator
    @wxheader{validate.h}

    wxValidator is the base class for a family of validator classes that mediate
    between a class of control, and application data.

    A validator has three major roles:

    @li to transfer data from a C++ variable or own storage to and from a control;
    @li to validate data in a control, and show an appropriate error message;
    @li to filter events (such as keystrokes), thereby changing the behaviour of the
        associated control.

    Validators can be plugged into controls dynamically.

    To specify a default, 'null' validator, use the symbol ::wxDefaultValidator.

    For more information, please see @ref overview_validator.

    @beginWxPythonOnly
    If you wish to create a validator class in wxPython you should
    derive the class from @c wxPyValidator in order to get Python-aware
    capabilities for the various virtual methods.
    @endWxPythonOnly

    @library{wxcore}
    @category{validator}

    @stdobjects
    ::wxDefaultValidator

    @see @ref overview_validator, wxTextValidator, wxGenericValidator
*/
class wxValidator : public wxEvtHandler
{
public:
    /**
        Constructor.
    */
    wxValidator();

    /**
        Destructor.
    */
    ~wxValidator();

    /**
        All validator classes must implement the Clone() function, which returns
        an identical copy of itself.

        This is because validators are passed to control constructors as references
        which must be copied. Unlike objects such as pens and brushes, it does not
        make sense to have a reference counting scheme to do this cloning, because
        all validators should have separate data.

        @returns this base function returns @NULL.
    */
    virtual wxObject* Clone() const;

    /**
        Returns the window associated with the validator.
    */
    wxWindow* GetWindow() const;

    /**
        This functions switches on or turns off the error sound produced by the
        validators if an invalid key is pressed.
    */
    void SetBellOnError(bool doIt = true);

    /**
        Associates a window with the validator.
    */
    void SetWindow(wxWindow* window);

    /**
        This overridable function is called when the value in the window must be
        transferred to the validator.

        @return @false if there is a problem.
    */
    virtual bool TransferFromWindow();

    /**
        This overridable function is called when the value associated with the
        validator must be transferred to the window.

        @return @false if there is a problem.
    */
    virtual bool TransferToWindow();

    /**
        This overridable function is called when the value in the associated window
        must be validated.

        @return @false if the value in the window is not valid; you may pop up an error
                dialog.
    */
    virtual bool Validate(wxWindow* parent);
};

/**
    An empty wxValidator instance.
*/
wxValidator wxDefaultValidator;
